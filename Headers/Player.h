//
// Created by kristianshevando on 10.5.17.
//

#ifndef COURSEWORK_PLAYER_H
#define COURSEWORK_PLAYER_H

#include <iostream>
#include "Birthday.h"

using namespace std;

class Player
{
private:
    int numb = 0;
    Birthday date;
    string name;
    Birthday birthday;
    string number;
    int games;
    int assists;
    int goals;
    int yc;
    int rc;
public:
    Player();
    void set_name(string);
    void set_birthday(string);
    void set_number(string);
    void set_games(int);
    void set_assists(int);
    void set_goals(int);
    void set_yc(int);
    void set_rc(int);

    string get_name2();
    string get_name();
    string get_birthday();
    string get_number();
    int get_games();
    int get_assists();
    int get_goals();
    int get_yc();
    int get_rc();

    bool isName(string);
    bool isBirthday(string);
    bool isNumber(string);
};


#endif //COURSEWORK_PLAYER_H
