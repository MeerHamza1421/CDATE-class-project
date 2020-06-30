#include <iostream>
#include "CDATE.h"
    using namespace std;
    int main()
    {
        cout << "\n***************************** Non Parameterize Constructor Call **********************\n";
        CDATE testobj1;   //As constructor overloading done in our header file this set value of data member to zero

        testobj1.print();  //to inspect constructor set values of data members to zero or not as set in header file
        cout << "\n**************************** Parameterize Constructor ****************************\n";
        CDATE testobj(28,2,2001);   //work as parameterize constructor

        testobj.print();	//to inspect parametrize constructor set values of data members accurately or not

        cout << "\n********************************* Data extracted from keyboard ********************************\n";

        testobj.readfromKB().print();   //to interact with keyboard and get data through keyboard at runtime

        cout << "\n********************** False vlaues to setter functions to inspect validate functions working ************************\n";

        testobj.setday(32).print();     // Set false values for inspecting of validation functions working

        testobj.setMonth(13).print();     //to check validate function works accurately on single components/data members or not

        testobj.setYear(1000).print();

        cout << "\n*********************** Correct values to setter funcitons *************************\n";

        cout << "\nWhole value of date set through Date setter funtion\n";

        testobj.setDate(1, 10, 2005).print();  //to set whole date if we want to change the date
        cout << "*********************************************************************";
        testobj.setday(12);  //to set day seprately

        cout << "\nValue from day setter funciton: \t" << testobj.getDay()
             << endl;  //Day value getter function to get setted day date

        testobj.setMonth(3);      //to set month seprately

        cout << "\nValue from Month setter funciton:\t" << testobj.getMonth()
             << endl;  //Month value getter function to get setted month value

        testobj.setYear(2000);  //to set year seperately

        cout << "\nValue from Year setter funciton:\t" << testobj.getYear()
             << endl;  //Year value getter function to get setted Year value

        cout << "\n********************* Copy constructor ****************************\n";

        CDATE dummyTestobj(testobj);  //to Call copy constructor

        dummyTestobj.print(); //to inspect copy constructor works properly or not
    }
    