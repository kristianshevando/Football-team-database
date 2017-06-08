//
// Created by kristianshevando on 6.5.17.
//

#ifndef COURSEWORK_ADMIN_H
#define COURSEWORK_ADMIN_H


#include "Authorization.h"
#include "Database.h"
#include "Protect.h"
#include <iostream>
#include "../bprinter-master/include/bprinter/table_printer.h"
using namespace bprinter;

class Admin
{
private:
Protect protect;
public:
    void Admin_Mode();
    void admin_mode_menu();

    void work_w_accounts();
    void work_w_accounts_menu();
    void work_w_database();
    void work_w_database_menu();

};


#endif //COURSEWORK_ADMIN_H
