//
// Created by kristianshevando on 31.5.17.
//

#include "Birthday.h"

Birthday::Birthday()
{

}

std::string Birthday::getString()
{
    std::string outPut = "";
    if(this->day < 10){
        outPut = "0" + std::to_string(this->day) + ".";
    }
    else{
        outPut =  std::to_string(this->day) + ".";
    }
    if(this->month < 10){
        outPut += "0" + std::to_string(this->month) + ".";
    }
    else{
        outPut += std::to_string(this->month) + ".";
    }
    outPut += std::to_string(this->year);
    return outPut;
}

void Birthday::parseString(std::string input)
{
    unsigned long firstDotPosition = input.find_first_of('.');
    if(firstDotPosition == EOF){
        throw WRONG_FORMAT;
    }
    unsigned long secondDotPosition = input.substr(firstDotPosition + 1).find_first_of('.') + (firstDotPosition + 1);

    if(secondDotPosition == firstDotPosition){
        throw WRONG_FORMAT;
    }
    this->day = stoi(input.substr(0, firstDotPosition));
    this->month = stoi(input.substr(firstDotPosition + 1, secondDotPosition - firstDotPosition));
    this->year = stoi(input.substr(secondDotPosition + 1, 4));
}

bool Birthday::isValid()
{
    try{
        if(this->day > MAX_DATE || this->day < MIN_DATE){
            throw WRONG_DAY;
        }
        else if(this->month > MAX_MONTH || this->month < MIN_MONTH){
            throw WRONG_MONTH;
        }
        else if(this->year > MAX_YEAR || this->year < MIN_YEAR){
            throw WRONG_YEAR;
        }
        return true;
    }
    catch(int excCode){
        switch(excCode){
            case WRONG_FORMAT:
                std::cout << "Wrong date's format.";
                break;
            case WRONG_DAY:
                std::cout << "Wrong day.";
                break;
            case WRONG_MONTH:
                std::cout << "Wrong month";
                break;
            case WRONG_YEAR:
                std::cout << "Wrong year.";
        }
        return false;
    }
}

void Birthday::setDate()
{
    std::string dateString = "";
    std::cin >> dateString;
    try{
        this->parseString(dateString);
    }
    catch(...){
        std::cout << "Wrong date's format. Retry: ";
        this->setDate();
    }
    if(!isValid()){
        std::cout << " Retry: ";
        this->setDate();
    }
}

void Birthday::setDate(std::string date) {
    this->parseString(date);
}

bool Birthday::operator<(Birthday date) {
    if(this->year < date.getYear()){
        return true;
    }
    else if(this->year == date.getYear() && this->month < date.getMonth()){
        return true;
    }
    else return this->year == date.getYear() && this->month == date.getMonth() && this->day < date.getDay();
}

int Birthday::getYear() {
    return this->year;
}

int Birthday::getMonth() {
    return this->month;
}

int Birthday::getDay() {
    return this->day;
}

bool Birthday::operator>(Birthday date) {
    if(this->year > date.getYear()){
        return true;
    }
    else if(this->year == date.getYear() && this->month > date.getMonth()){
        return true;
    }
    else return this->year == date.getYear() && this->month == date.getMonth() && this->day > date.getDay();
}

bool Birthday::operator==(Birthday date) {
    return this->year == date.getYear() && this->month == date.getMonth() && this->day == date.getDay();
}

bool Birthday::operator<=(Birthday date) {
    if(this->year <= date.getYear()){
        return true;
    }
    else if(this->year == date.getYear() && this->month <= date.getMonth()){
        return true;
    }
    else return this->year == date.getYear() && this->month == date.getMonth() && this->day <= date.getDay();
}

bool Birthday::operator>=(Birthday date) {
    if (this->year >= date.getYear()) {
        return true;
    }
    else if (this->year == date.getYear() && this->month >= date.getMonth())
    {
        return true;
    }
    else
        return this->year == date.getYear() && this->month == date.getMonth() && this->day >= date.getDay();
}