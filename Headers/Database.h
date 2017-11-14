//
// Created by kristianshevando on 9.5.17.
//

#ifndef COURSEWORK_DATABASE_H
#define COURSEWORK_DATABASE_H

#include "Admin.h"
#include "Player.h"
#include "Protect.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../bprinter-master/include/bprinter/table_printer.h"

using namespace bprinter;

const int ID = 0;
const int NAME = 1;
const int BIRTHDAY = 2;
const int NUMBER = 3;
const int GAMES = 4;
const int ASSISTS = 5;
const int GOALS = 6;
const int YC = 7;
const int RC = 8;

const int SEARCHNAME = 0;
const int SEARCHBIRHDAY = 1;
const int SEARCHNUMBER = 2;

const int SORTGAMES = 0;
const int SORTASSISTS = 1;
const int SORTGOALS = 2;

const string TEAM = "ourfile.txt";

class Database
{
private:
    Protect protect;
    vector<Player> players;
    vector<int> search_by_name(string);
    vector<int> search_by_birthday(string);
    vector<int> search_by_number(string);

    void head(TablePrinter &);

    int looking_for_player(string);
    void read_database();
    void create_database();

    void sortGames(int, int);
    void sortAssists(int, int);
    void sortGoals(int, int);
public:
    Database();
    Player for_read(string);
    void save_database();
    void add_player();
    void delete_player();
    void view_all_players();
    void change_player();
    vector<int> search_a_player(int, string);

    void search_mode();

    void show_records(vector<int> &);

    void search_name_mode();
    void search_birthday_mode();
    void search_number_mode();

    void check_player(int);
    void show_player(int);

    void sort_mode();
    void sortPlayersBy(int);

    void show_best_players();
    void for_best_players(int, int, vector<int> &, vector<Player> &);
    
    void show_rc();
};


#endif //COURSEWORK_DATABASE_H
