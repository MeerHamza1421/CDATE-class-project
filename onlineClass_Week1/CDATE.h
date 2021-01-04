//
// Created by AB on 6/30/2020.
//

#ifndef ONLINECLASS_WEEK1_CDATE_H
#define ONLINECLASS_WEEK1_CDATE_H

class CDATE {
    // ------------------ Private members and methods ----------------------------
    int year, month, day;
    void validate();

    // Static data members

    static int daysOfmonth[13];
    static char strMonth[13][4];
    static char stringMonth[13][10];

    //------------------ Public members and methods -----------------------------
public:

    //--------------------- Declaring members ------------------------------------
    int option;		//to get option from user in what format user want to print date

    CDATE();
    CDATE(int day, int month, int year);
    CDATE(const CDATE& ctr);
    ~CDATE();

    void print(int opt);
    bool isLeapyear();
    void userinteracton();

    //------------------------- Static Methods ----------------------------------

    static  bool setMindate(int day,int month,int year);
    static  bool setMaxdate(int day,int month,int year);

    // -------------------Setters Functions ------------------------

    CDATE& readfromKB();  //   make referance return type to enable cascading in these functions
    CDATE& setday(int day);
    CDATE& setMonth(int month);
    CDATE& setYear(int year);
    CDATE& setDate(int day, int month, int year);

    //------------------- Getter Functions ---------------------------

    int getMonth();
    int getYear();
    int getDay();
};
#endif //ONLINECLASS_WEEK1_CDATE_H
