/*
*****************************************************************************
                           Milestone 5
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
#include "Book.h"
#include "Lib.h"
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
namespace seneca{

Book::Book(){
    
    m_AuthorName = nullptr;
}

Book::Book(const Book& other){
    
    operator=(other);
    
}


Book& Book::operator=(const Book& other){
    
    if (this != &other && other.m_AuthorName)
    {
        Publication::operator=(other);
        delete [] m_AuthorName;
        m_AuthorName = new char[strlen(other.m_AuthorName) + 1];
        strcpy(m_AuthorName, other.m_AuthorName);
    }
    
    return *this;
}

Book::~Book(){
    
    delete [] m_AuthorName;
    m_AuthorName = nullptr;
    
}


char Book::type()const{
    
    return 'B';
    
}

std::ostream& Book::write(std::ostream& os) const{
    
    Publication::write(os);
    
    if (Publication::conIO(os))
    {
        os << ' ';
        if (strlen(m_AuthorName) > SENECA_AUTHOR_WIDTH)
        {
            for (int i = 0; i < SENECA_AUTHOR_WIDTH; i++) {
                os << m_AuthorName[i];
            }
        }else
        {
            os << setw(SENECA_AUTHOR_WIDTH) << left << m_AuthorName ;
        }
        os << " |";
    }
    else{
        
        os << '\t' << m_AuthorName;
                
    }
    
    return os;
}

std::istream& Book::read(std::istream& is){
    
    char AuthorName[256]{};
    
    Publication::read(is);
    
    delete [] m_AuthorName;
    m_AuthorName = nullptr;
    
    if (Publication::conIO(is))
    {
        is.ignore(1000, '\n');
        cout << "Author: ";
        is.get(AuthorName, 256 , '\n');
    }
    else
    {
        is.ignore(1000, '\t');
        is.get(AuthorName, 256 , '\n');
    }
    
    if (!is.fail()) {
        m_AuthorName = new char[strlen(AuthorName) + 1];
        strcpy(m_AuthorName, AuthorName);
    }
    
    return is;
    
}

void Book::set(int member_id){
    
    Publication::set(member_id);
    Publication::resetDate();
}

Book::operator bool() const{
    
    return m_AuthorName && Publication::operator bool() ;
    
}


}

