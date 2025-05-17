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

#ifndef Menu_h
#define Menu_h

#include <stdio.h>
#include <iostream>


namespace seneca {

const unsigned int MAX_MENU_ITEMS = 20;

class Menu ;

class MenuItem {
private:
friend class Menu;
    
    char* content{nullptr};
    MenuItem(const char* content = nullptr);

    MenuItem(const MenuItem&) = delete;
    MenuItem& operator=(const MenuItem&) = delete;
    
    ~MenuItem();
    
    operator bool() const;
    operator const char* ()const;
    
    std::ostream& display_Items(std::ostream& ostr = std::cout)const;
    
};



class Menu {
public:
    MenuItem* m_title{nullptr};
    MenuItem* items[MAX_MENU_ITEMS];
    unsigned int m_tracker = 0;
    

    Menu();
    Menu(const char* title);
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;
    
    std::ostream& display_Title(std::ostream& ostr = std::cout)const;
    std::ostream& display_All(std::ostream& ostr = std::cout)const;
    
    unsigned int run();
    unsigned int operator~();
    Menu& operator<<(const char* menuitemConent);
    operator int()const;
    operator unsigned int()const;
    operator bool() const;
    const char* operator[](unsigned i) const;
    ~Menu();
    
    char* ContentGetter()const;
};

std::ostream& operator<<(std::ostream& os , const Menu& M);

}




#endif /* Menu_hpp */
