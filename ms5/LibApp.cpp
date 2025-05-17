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
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Menu.h"
#include "LibApp.h"
#include "Book.h"
#include "PublicationSelector.h"

using namespace std;
namespace seneca {

bool LibApp::confirm(const char* message){
    
    Menu confrim(message);
    confrim << "Yes";
    return (confrim.run() == 1);
}

void LibApp::load() {
    
    cout << "Loading Data" << endl ;
    ifstream file(m_dataFname);
    char ch{};
    for (int i = 0; file ; i++) { /////
        file >> ch;
        file.ignore();
        
        if (file) {
            if (ch == 'P'){
                m_PPA[i] = new Publication;
            }
            else if (ch == 'B'){
                m_PPA[i] = new Book;
            }
            if (m_PPA[i]) {
                file >> *m_PPA[i];
                m_NOLP++;
                m_LLRN = m_PPA[i]->getRef();
            }
        }
    }
}

void LibApp::save(){
    
    cout << "Saving Data" << endl;
    ofstream file(m_dataFname);
    for (int i = 0 ; i < m_NOLP; i++)
    {
        if (m_PPA[i]->getRef() != 0) {
            file << *m_PPA[i] << endl; //pointer or not ???
        }
    }
    
}

int LibApp::search(int mode){
    
//   cout<< "Searching for publication" << endl;
    int type = m_typeMenu.run();
    char choice{};
    
    switch (type) {
        case 1:
            choice = 'B';
            break;
        case 2:
            choice = 'P';
            break;
        default:
            cout << "Aborted!" << endl;
            break;
    }
    PublicationSelector P("Select one of the following found matches:" , 15);
    char title[256]{};
    cout << "Publication Title: ";
    cin.ignore();
    cin.get(title , 256);
 
//  cin >> title;
    for (int i = 0 ; i < m_NOLP; i++) {
        switch (mode) {
            case 1:
                if (m_PPA[i]->getRef() != 0 && m_PPA[i]->operator==(title) && m_PPA[i]->type() == choice ) {
                    P << m_PPA[i];
                }
                break;
            case 2:
                if (m_PPA[i]->getRef() != 0 && m_PPA[i]->operator==(title) && m_PPA[i]->type() == choice && m_PPA[i]->onLoan()) {
                    P << m_PPA[i];
                }
                break;
            case 3:
                if (m_PPA[i]->getRef() != 0 && m_PPA[i]->operator==(title) && m_PPA[i]->type() == choice && !m_PPA[i]->onLoan()) {
                    P << m_PPA[i];
                }
                break;
        }
        
      
    }
    int selection {};
    if (P) {
        cin.clear();
        cin.ignore();
        P.sort();
        selection = P.run();
        if(selection)
        {
            cout << *getPub(selection) << endl; //this function will then be created later in the code...
        }
        else
        {
            cout << "Aborted!\n" << endl;
        }
    }
    else
    {
        cout << "No matches found!" << endl << endl;
    }
    
    return selection;
}


Publication* LibApp::getPub(int libRef){
    Publication* P {nullptr};
    for (int i = 0; i < m_NOLP; i++)
    {
        if (m_PPA[i]->getRef() == libRef ) {
            P = m_PPA[i];
        }
    }
    return P;
}

void LibApp::returnPub(){
    
    Date current{}; //initilaze
    cout << "Return publication to the library" <<endl;
    int selection = search(2);
    if (selection) {
        bool ret = confirm("Return Publication?");
        
        if (ret == true)
        {
            int lateDays = current - getPub(selection)->checkoutDate();
            if(lateDays > 15)
            {
                double penaltyValue = (lateDays - 15) * 0.50 ;
                cout.setf(ios::fixed);
                cout.precision(2);
                cout << "Please pay $" << penaltyValue << " penalty for being " << lateDays - 15 << " days late!" << endl;
                getPub(selection)->set(0);
                m_changed = true;
                cout << "Publication returned" << endl <<  endl;
            }
        }
    }
    
    
}

void LibApp::newPublication(){
    
    bool exit = false;
        if (m_NOLP == SENECA_LIBRARY_CAPACITY)
        {
            cout << "Library is at its maximum capacity!" << endl;
            exit = true;
        }
            if (exit == false)
            {
                cout << "Adding new publication to the library" << endl;
                int type = m_typeMenu.run();
                Publication* P = nullptr; ///nullptr??
                switch (type) {
                        
                    case 1:
                        P = new Book;
                        cin >> *P;
                        break;
                    case 2:
                        P = new Publication;
                        cin >> *P;
                        break;
                    default:
                        cout <<"Aborted!" << endl;
                        exit = true;
                        break;
                }
                //    case 1:
                //        m_PPA[m_NOLP] = new Book;
                //        cin >> *m_PPA[m_NOLP];
                //        break;
                //    case 2:
                //        m_PPA[m_NOLP] = new Publication;
                //        cin >> *m_PPA[m_NOLP];
                //        break;
                
                if (cin.fail())
                {
                    cin.ignore(1000, '\n');
                    cin.clear();
                    cout << "Aborted!" << endl;
                    delete P; //Avoid memory leak????
                    exit = true;
                }
                else if(exit == false )
                {
                    bool ret = confirm("Add this publication to the library?");
                    if (ret == false)
                    {
                        cout << "Aborted!" << endl;
                        exit = true;
                    }
                    else{
                        if (P)
                        {
                            m_LLRN++;
                            P->setRef(m_LLRN);
                            m_PPA[m_NOLP] = P; //remove ++ if bugs...
                            m_NOLP++;
                            m_changed = true;
                            cout << "Publication added" << endl;
                        }
                        else
                        {
                            cout << "Failed to add publication!";
                            delete P;
                        }
                    }
                }
            } cout << endl;
        
    
}
void  LibApp::removePublication(){
    cout << "Removing publication from the library" << endl;
   int selection = search(1);
    if (selection) {
        bool ret = confirm("Remove this publication from the library?");
         if (ret == true) {
             getPub(selection)->setRef(0);
             m_changed = true;
             cout << "Publication removed" << endl <<  endl;
         }else{
             cout << endl;
         }
    }
  
}

void LibApp::checkOutPub(){
    int number {};
    cout << "Checkout publication from the library" << endl;
   int selection = search(3);
    if (selection)
    {
        bool ret = confirm("Check out publication?");
         if (ret == true)
         {
             cout << "Enter Membership number: ";
             cin >> number;
             while (number < 10000  || number > 99999) {
                 
                 cout << "Invalid membership number, try again: ";
                 cin >> number;
                 
             }
                 getPub(selection)->set(number);
                 m_changed = true;
                 cout << "Publication checked out" << endl <<  endl;
         }else{
             cout << endl;
         }
    }
   
}

LibApp::LibApp(const char *name /*, bool chanced*/) : m_typeMenu("Choose the type of publication:") , m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
{
            m_typeMenu << "Book" ;
            m_typeMenu << "Publication";
            m_mainMenu << "Add New Publication";
            m_mainMenu << "Remove Publication";
            m_mainMenu << "Checkout publication from library";
            m_mainMenu << "Return publication to library";

            m_exitMenu << "Save changes and exit";
            m_exitMenu << "Cancel and go back to the main menu";

    if(name)
    {
        strcpy(m_dataFname, name);
    }
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

LibApp::~LibApp()
{
    for(int i = 0; i < m_NOLP; i++){
        delete m_PPA[i];
        m_PPA[i] = nullptr;
    }
}

}
