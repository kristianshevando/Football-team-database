//
// Created by kristianshevando on 31.5.17.
//

#ifndef COURSEWORK_BIRTHDAY_H
#define COURSEWORK_BIRTHDAY_H
#include <string>
#include <iostream>

using namespace std;

const int MIN_DATE = 1;
const int MAX_DATE = 31;
const int MIN_MONTH = 1;
const int MAX_MONTH = 12;
const int MIN_YEAR = 1800;
const int MAX_YEAR = 3000;

const int WRONG_DAY = 1;
const int WRONG_MONTH = 2;
const int WRONG_YEAR = 3;
const int WRONG_FORMAT = 4;

class Birthday
{
private:
    int day;
    int month;
    int year;
    void parseString(std::string);
    bool isValid();
public:
    Birthday();
    std::string getString();
    int getYear();
    int getMonth();
    int getDay();
    void setDate();
    void setDate(std::string);
    bool operator < (Birthday);
    bool operator > (Birthday);
    bool operator == (Birthday);
    bool operator <= (Birthday);
    bool operator >= (Birthday);
};


#endif //COURSEWORK_BIRTHDAY_H
