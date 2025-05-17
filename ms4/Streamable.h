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

#ifndef Streamable_h
#define Streamable_h
#include <iostream>
namespace seneca{

class Streamable{
    
public:
    virtual std::ostream& write(std::ostream& os) const = 0;
    virtual std::istream& read(std::istream& is) = 0;
    virtual bool conIO(std::ios& io) const = 0;
    virtual operator bool () const = 0;
    virtual ~Streamable() = default;
    
};


std::ostream& operator<<(std::ostream& os ,const Streamable& S);
std::istream& operator>>(std::istream& is ,Streamable& S);

}

#endif /* Streamable_hpp */
