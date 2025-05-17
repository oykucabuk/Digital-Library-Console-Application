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

#include "Streamable.h"
#include "Date.h"
#ifndef Publication_h
#define Publication_h

namespace seneca {

class Publication : public Streamable{
    
private:
    
    char* m_title{};
    char m_shelfld[5];
    int m_membership;
    int m_libRef;
    Date m_date;
    


public:
    
    Publication();
    
    virtual void set(int member_id);
       // Sets the membership attribute to either zero or a five-digit integer.
    void setRef(int value);
       // Sets the **libRef** attribute value
    void resetDate();
       // Sets the date to the current date of the system.
 
    virtual char type()const;
       //Returns the character 'P' to identify this object as a "Publication object"
    bool onLoan()const;
       //Returns true is the publication is checkout (membership is non-zero)
    Date checkoutDate()const;
       //Returns the date attribute
    bool operator==(const char* title)const;
       //Returns true if the argument title appears anywhere in the title of the
       //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
    operator const char* ()const;
       //Returns the title attribute
    int getRef()const;
       //Returns the libRef attirbute.
    
    
     bool conIO(std::ios& io) const;
     std::ostream& write(std::ostream& os) const;
     std::istream& read(std::istream& is);
     operator bool () const;
    
    
    
    Publication(const Publication& P);
    Publication& operator=(const Publication& P);
    ~Publication();
};

}

#endif /* Publication_hpp */
