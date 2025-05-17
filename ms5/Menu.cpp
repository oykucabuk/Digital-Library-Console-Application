/*
*****************************************************************************
                            Milestone 2
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
#include <string.h>
#include "Menu.h"
using namespace std;
namespace seneca {
    
MenuItem::MenuItem(const char* content2){
    if (content2) {
        content = new char[strlen(content2) + 1];
        strcpy(content, content2);
    }
    else
    {
        content = nullptr;
    }
}

MenuItem::~MenuItem(){
    
    delete[] content;
    content = nullptr;
    
}

MenuItem::operator bool() const{
    
    return content != nullptr;
}


MenuItem::operator const char* ()const{
    
    return content;
}

ostream& MenuItem::display_Items(ostream& ostr)const{
    if (content != nullptr) {
      
            ostr << content ;
       
    }
    
    return ostr;
}


Menu::Menu(){
    for (unsigned i = 0; i < MAX_MENU_ITEMS; i++) {
        items[i] = nullptr;
    }
    m_title = nullptr;
}

Menu::Menu(const char* title){
    m_title = new MenuItem(title);
    for (unsigned i = 0; i < MAX_MENU_ITEMS; i++) {
        items[i] = nullptr;
    }
}

Menu::~Menu(){
    delete m_title;
    for (unsigned i = 0; i < m_tracker; i++) {
        delete items[i];
    }
    
}

ostream& Menu::display_Title(ostream& ostr)const{
    if (m_title) {
        ostr << m_title->content ;
    }
    return ostr;
}


ostream& Menu::display_All(ostream& os)const{
    
    if (m_title) {
        display_Title(os);
        os << endl;
    }
   
    for (unsigned i = 0; i < m_tracker; i++)
    {
      //  os.width(2);
        os << " " << (i + 1) << "- " << items[i]->content << endl;
    }
    os << " 0- Exit" << '\n' << "> "; 
    
    return os;
}


 unsigned int Menu::run(){
    
     display_All();
     unsigned int selected ;
    // bool flag = 0;
     cin >> selected;
     while (cin.fail() || selected > m_tracker )
     {
         if ( cin.fail() || selected > m_tracker || selected < 0) {
             cout << "Invalid Selection, try again: " ;
             cin.clear();
             cin.ignore(1000, '\n');
         }
         cin >> selected;
         cin.clear();
     }
     return selected;
}

unsigned int Menu::operator~(){
    display_All();
    unsigned int selected ;
    cin >> selected;
    while (selected < 0 && selected > m_tracker)
    {
        cin >> selected;
        if (selected < 0 && selected > m_tracker) {
            cout << "Invalid Selection, try again: " ;
        }
    }
    return selected;
}

Menu& Menu::operator<<(const char* menuitemConent){
   
    if (m_tracker < MAX_MENU_ITEMS) {
        items[m_tracker] = new MenuItem(menuitemConent);
        m_tracker++;
    }
    
    return *this;
}

Menu::operator int()const{
    return m_tracker;
}


Menu::operator unsigned int()const{
    return m_tracker;
}

Menu::operator bool() const{
    
    return m_tracker > 0;
}

ostream& operator<<(ostream& os , const Menu& M){
    
    M.display_Title();
    
    return os;
}

const char* Menu::operator[](unsigned i) const{
    return *items[i % m_tracker];
}

char* Menu::ContentGetter()const
{
    return m_title->content;
}

}
