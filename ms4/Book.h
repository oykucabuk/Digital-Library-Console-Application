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

#ifndef Book_h
#define Book_h
#include "Publication.h"
#include <stdio.h>

namespace seneca{

class Book : public Publication{
    char* m_AuthorName;
    
public:
    Book();
    Book(const Book& other);
    Book& operator=(const Book& other);
    ~Book();
    
    char type()const;
    std::ostream& write(std::ostream& os) const;
    std::istream& read(std::istream& is);
    operator bool() const;
    void set(int member_id);


};
}





#endif /* Book_hpp */
