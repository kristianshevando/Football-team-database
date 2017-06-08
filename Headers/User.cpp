//
// Created by kristianshevando on 6.5.17.
//

#include "User.h"

void User::User_Mode()
{
    Database database;
    Protect protect;
    int choice;
    while(true)
    {
        this->user_mode_menu();
        choice = protect.protect();
        switch(choice)
        {
            case 1:
                database.view_all_players();
                this->User_Mode();
                break;
            case 2:
                database.search_mode();
                this->User_Mode();
                break;
            case 3:
                database.sort_mode();
                this->User_Mode();
                break;
            case 4:
                database.show_best_players();
                this->User_Mode();
                break;
            case 5:
                database.show_rc();
                this->User_Mode();
                break;
            default:
                break;
        }
        break;
    }
}

void User::user_mode_menu()
{
    std::cout << "1.Show all players\n";
    std::cout << "2.Search a player\n";
    std::cout << "3.Sorting players\n";
    std::cout << "4.Show six best players(goals + assists)\n";
    std::cout << "5.Show all red carders\n";
    std::cout << "0.EXIT\n";
    std::cout << "Just choose the number: ";
}