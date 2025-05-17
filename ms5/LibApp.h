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

#include "Menu.h"
#include "Publication.h"
#include "Lib.h"
#ifndef LibApp_h
#define LibApp_h

#include <stdio.h>
namespace seneca {
   class LibApp {
       
   private:
       char m_dataFname[256]{};
       Publication* m_PPA[SENECA_LIBRARY_CAPACITY]; //Publication Pointers Array
       int m_NOLP{};  //Number Of Loaded Publications
       int m_LLRN{};  //Last Library Reference Number
       Menu m_typeMenu ;
       
       Publication* getPub(int libRef);
       
       bool m_changed = false;
       Menu m_mainMenu ;
       Menu m_exitMenu ;
       bool confirm(const char* message);
       void load();  // prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       int search(int mode);  // prints: "Searching for publication"<NEWLINE>
       
       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */
       void newPublication();
       void removePublication();
       void checkOutPub();
   public:
       LibApp(const char *name = nullptr /*, bool changed = false*/);
       void run();
       ~LibApp();
   };
}

#endif /* LibApp_hpp */
