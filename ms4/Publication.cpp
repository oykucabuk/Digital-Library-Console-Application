/*
*****************************************************************************
                           Milestone 4
Full Name  : Oyku CABUK
Student ID#: 149790230
Email      : ocabuk@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <cstring>
#include <iomanip>
#include "Date.h"
#include "Publication.h"
#include "Lib.h"
namespace seneca {

Publication::Publication(){
   
   m_title = nullptr;
   m_shelfld[0] = '\0';
   m_membership = 0;
   m_libRef = -1;
   
   
}

void Publication::set(int member_id){
   
    m_membership = member_id;
   
}

void Publication::setRef(int value){
   
   m_libRef = value;
}

void Publication::resetDate(){
   
   Date current;
   m_date = current;
   
}


char Publication::type()const{
   
   return 'P';
}

bool Publication::onLoan()const{
   
   return (m_membership != 0);
}

Date Publication::checkoutDate()const{
   
   return m_date;
}

bool Publication::operator==(const char* title)const{
   
   return strstr(m_title, title) != NULL;
   
}

Publication::operator const char* ()const{
   
   return m_title;
   
}

int Publication::getRef()const{
   
   return m_libRef;
   
}

bool Publication::conIO(std::ios& io) const{
   
   return &io == &std::cin || &io == &std::cout ;
}

std::ostream& Publication::write(std::ostream& os) const{
   
   if (conIO(os))
   {
       os << "| " << m_shelfld << " | " ;
       if (strlen(m_title) > SENECA_TITLE_WIDTH)
       {
           for (int i = 0; i < SENECA_TITLE_WIDTH ; i++)
           {
               os << m_title[i];
           }
           os << " | ";
       }
       else
       {
           os <<std::left << std::setw(SENECA_TITLE_WIDTH) << std::setfill('.')<<
           m_title << " | " ;
       }
       
       if (m_membership != 0) {
           os << m_membership << " | " ;
       }
       else
       {
         //  os << std::setw(5) << std::setfill(' ') << " N/A" << " | ";
           os << " N/A " << " | ";
       }
       os << m_date << " |";
   }
   else
   {
       os<< type() << '\t' << getRef() << '\t' <<
      m_shelfld << '\t' << m_title << '\t' << m_membership <<
       '\t' << m_date ;
   }
   return os;
}

std::istream& Publication::read(std::istream& is){
   
   resetDate();
   delete[] m_title;
   
   std::string title{};
   std::string shelfId{};
   int membership = 0;
   int libRef = -1;
   Date date;
   
   if (conIO(is))
   {
       std::cout << "Shelf No: ";
       is >> shelfId;
       is.clear();
       if (shelfId.length() != SENECA_SHELF_ID_LEN)
       {
           is.setstate(std::ios::failbit);
           
       }else
       {
           is.ignore(1000, '\n');;
       }
       std::cout << "Title: ";
       std::getline(is, title, '\n');
       std::cout << "Date: ";
       is >> date;
       
   }
   else
   {
       is >> libRef;
       is.ignore();
       std::getline(is , shelfId, '\t');
       std::getline(is, title, '\t');
       is >> membership;
       is.ignore();
       is >> date;
   }
   
   if (!date) {
       is.setstate(std::ios::failbit);
   }
   
   if (is)
   {
       m_title = new char[title.length() + 1];
       strcpy(m_title, title.c_str());
       strcpy(m_shelfld, shelfId.c_str());
       m_membership = membership;
       m_date = date;
       m_libRef = libRef;
   }
   return is;
   
}

   Publication::operator bool () const{
       
       return  m_title != nullptr  && m_shelfld[0] != '\0';
   }


Publication::Publication(const Publication& P){
   
   if (P) {
       operator=(P);
   }
}

Publication& Publication::operator=(const Publication& P){
   
   if (this != &P && P) {
       delete [] m_title;
       m_title = new char[strlen(P.m_title) + 1];
       strcpy(m_title, P.m_title);
       strcpy(m_shelfld, P.m_shelfld);
       m_libRef = P.m_libRef;
       m_membership = P.m_membership;
       m_date = P.m_date;
   }
   return *this;
}

Publication::~Publication(){
   delete [] m_title;
}


}
