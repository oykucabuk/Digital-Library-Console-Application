


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
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Menu.h"
#include "Utils.h"
#include "LibApp.h"
using namespace std;
namespace seneca {

bool LibApp::confirm(const char* message){
    
    Menu confrim(message);
    confrim << "Yes";
    return (confrim.run() == 1);
}

void LibApp::load() {
    
    cout << "Loading Data" << endl ;
     
}

void LibApp::save(){
    
    cout << "Saving Data" << endl;
    
}

void LibApp::search(){
    
    cout<< "Searching for publication" << endl;
    
}

void LibApp::returnPub(){
    
    search();
    cout << "Returning publication" << endl
    << "Publication returned" << endl <<  endl;
    m_changed = true;
    
}

void LibApp::newPublication(){
    cout << "Adding new publication to library" << endl;
    bool ret = confirm("Add this publication to library?");
    if (ret == true) {
        m_changed = true;
        cout << "Publication removed" << endl << endl;
    }else{
        cout << endl;
    }
    
    
}
void  LibApp::removePublication(){
    cout << "Removing publication from library" << endl;
    search();
   bool ret = confirm("Remove this publication from the library?");
    if (ret == true) {
        m_changed = true;
        cout << "Publication removed" << endl <<  endl;
    }else{
        cout << endl;
    }
}

void LibApp::checkOutPub(){
    search();
   bool ret = confirm("Check out publication?");
    if (ret == true) {
        m_changed = true;
        cout << "Publication checked out" << endl <<  endl;
    }else{
        cout << endl;
    }
}

LibApp::LibApp() : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
{
            m_mainMenu << "Add New Publication";
            m_mainMenu << "Remove Publication";
            m_mainMenu << "Checkout publication from library";
            m_mainMenu << "Return publication to library";

            m_exitMenu << "Save changes and exit";
            m_exitMenu << "Cancel and go back to the main menu";

            load();
    
}

void LibApp::run(){
    bool terminate = false;
    do {
        int choice = m_mainMenu.run();
        switch (choice) {
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            case 0:
                if (m_changed == false)
                {
                    terminate = true;
                }
                else
                {
                    unsigned int selected = m_exitMenu.run();
                    switch (selected) {
                        case 1:
                            save();
                            terminate = true;
                            break;
                        case 2:
                            cout << endl;
                            break;
                        case 0:
                            bool confrim = confirm("This will discard all the changes are you sure?");
                            if (confrim == true) {
                                
                                terminate = true;
                                
                            }else {
                                cout << endl;
                            }
                            break;
                       
                    }
                }
                break;
        
        }
        
    } while (terminate == false);
    
    cout << endl
         << "-------------------------------------------" << endl
         << "Thanks for using Seneca Library Application" << endl;
    
}


}
