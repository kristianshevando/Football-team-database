//
// Created by kristianshevando on 21.5.17.
//

#ifndef COURSEWORK_ACCOUNT_H
#define COURSEWORK_ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account
{
private:
    string login;
    string password;
    bool isAdmin;
public:
    void setlog(string);
    void setpass(string);
    void setrole(string);
    string getlog();
    string getpas();
    string admin_or_user();

};


#endif //COURSEWORK_ACCOUNT_H
