#ifndef BEFOREQUARANTINE_CDATE_H
#define BEFOREQUARANTINE_CDATE_H

class CDATE {
    // ------------------ Private members and methods ----------------------------
    int year, month, day;
    void validate();
    //------------------ Public members and methods -----------------------------
public:

    //--------------------- Declaring members ------------------------------------

    CDATE();
    CDATE(int day, int month, int year);
    CDATE(const CDATE& ctr);
    ~CDATE();
    void print();
    bool isLeapyear();

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

#endif //BEFOREQUARANTINE_CDATE_H