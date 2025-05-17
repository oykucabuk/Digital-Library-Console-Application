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

#include "Streamable.h"

namespace seneca{

std::ostream& operator<<(std::ostream& os ,const Streamable& S){
    if (S) {
        S.write(os);
    }
    
    return os;
}
std::istream& operator>>(std::istream& is ,Streamable& S){
    
    return S.read(is);
}

}
