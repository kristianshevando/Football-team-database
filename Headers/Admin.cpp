//
// Created by kristianshevando on 6.5.17.
//
#include "Admin.h"

void Admin::admin_mode_menu()
{
    std::cout << "1.Working with accounts\n";
    std::cout << "2.Working with database\n";
    std::cout << "0.EXIT\n";
    std::cout << "Just choose the number: ";
}

void Admin::Admin_Mode()
{
    Database database;
    int choice;
    while(true)
    {
        this->admin_mode_menu();
        choice = this->protect.protect();
        switch(choice)
        {
            case 1:
                this->work_w_accounts();
                break;
            case 2:
                this->work_w_database();
                break;
            default:
                break;
        }
        break;
    }
}

void Admin::work_w_accounts()
{
    Authorization authorization;
    int choice;
    while(true)
    {
        this->work_w_accounts_menu();
        choice = this->protect.protect();
        switch (choice) {
            case 1:
                authorization.create_account();
                this->work_w_accounts();
                break;
            case 2:
                authorization.delete_account();
                this->work_w_accounts();
                break;
            case 3:
                authorization.watch_accounts();
                this->work_w_accounts();
                break;
            default:
                this->Admin_Mode();
        }
        break;
    }
}

void Admin::work_w_accounts_menu()
{
    cout << "1.Create account\n";
    cout << "2.Delete account\n";
    cout << "3.Show accounts\n";
    cout << "0.EXIT\n";
    cout << "Just choose the number: ";
}

void Admin::work_w_database()
{
    Database database;
    int choice;
    while(true)
    {
        this->work_w_database_menu();
        choice = this->protect.protect();
        switch(choice)
        {
            case 1:
                database.add_player();
                this->work_w_database();
                break;
            case 2:
                database.view_all_players();
                this->work_w_database();
                break;
            case 3:
                database.change_player();
                this->work_w_database();
                break;
            case 4:
                database.sort_mode();
                this->work_w_database();
                break;
            case 5:
                database.search_mode();
                this->work_w_database();
                break;
            case 6:
                database.show_best_players();
                this->work_w_database();
                break;
            case 7:
                database.show_rc();
                this->work_w_database();
                break;
            case 8:
                database.delete_player();
                this->work_w_database();
                break;
            default:
                this->Admin_Mode();
        }
        break;
    }
}

void Admin::work_w_database_menu()
{
    cout << "1.Add new information\n";
    cout << "2.View all players\n";
    cout << "3.Change player\n";
    cout << "4.Sorting players\n";
    cout << "5.Search a player\n";
    cout << "6.Sort players(goals + assists)\n";
    cout << "7.View all red carders\n";
    cout << "8.Delete some player\n";
    cout << "0.EXIT\n";
    cout << "Just choose the number: ";
}
