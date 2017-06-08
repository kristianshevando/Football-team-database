//
// Created by kristianshevando on 20.5.17.
//

#ifndef COURSEWORK_AUTHORIZATION_H
#define COURSEWORK_AUTHORIZATION_H

#include "Account.h"
#include "Admin.h"
#include "User.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../bprinter-master/include/bprinter/table_printer.h"

using namespace bprinter;

const string ACCOUNTS = "users.txt";
const int LOGIN = 0;
const int PASSWORD = 1;
const int ROLE = 2;

class Authorization
{

private:
Account account;
vector<Account> accounts;
Account for_read_db(std::string);
int looking_for_account(std::string);

public:
Authorization();
std::string come_in();
void read_db();
void create_db_default();
void create_fa_default();
void create_account();
void delete_account();
void watch_accounts();
void save_account();

};


#endif //COURSEWORK_AUTHORIZATION_H
