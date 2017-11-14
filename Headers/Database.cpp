//
// Created by kristianshevando on 9.5.17.
//

#include "Database.h"


Database::Database()
{
    this->read_database();
}


void Database::read_database()
{
    string buffer = "";
    ifstream fin;
    fin.open(TEAM);
    if(fin.is_open())
    {
        while (fin.peek() != EOF)
        {
            getline(fin, buffer);
            this->players.push_back(for_read(buffer));
        }
    }
    else
    {
        cout << "Database file doesn't exist.\n";
        cout << "It will be created by default.\n";
        this->create_database();
    }
    fin.close();
}

Player Database::for_read(string buffer)
{
    Player player;
    vector<string> vector1;
    string note = "";
    ifstream fin;
    fin.open(TEAM);
    for(int i = 0; i < buffer.size(); i++)
    {
        if(buffer[i] == '\"'){
            i++;
            while(true){
                note += buffer[i];
                i++;
                if(buffer[i] == '\"'){
                    vector1.push_back(note);
                    note = "";
                    break;
                }
            }
        }
    }
    player.setID(stoi(vector1[ID]));
    player.set_name(vector1[NAME]);
    player.set_birthday(vector1[BIRTHDAY]);
    player.set_number(vector1[NUMBER]);
    player.set_games(stoi(vector1[GAMES]));
    player.set_assists(stoi(vector1[ASSISTS]));
    player.set_goals(stoi(vector1[GOALS]));
    player.set_yc(stoi(vector1[YC]));
    player.set_rc(stoi(vector1[RC]));
    fin.close();
    return player;
}

void Database::head(TablePrinter & tablePrinter)
{
    tablePrinter.AddColumn("<>", 4);
    tablePrinter.AddColumn("Name", 12);
    tablePrinter.AddColumn("Birthday", 12);
    tablePrinter.AddColumn("Number", 6);
    tablePrinter.AddColumn("Games", 5);
    tablePrinter.AddColumn("Assists", 8);
    tablePrinter.AddColumn("Goals", 5);
    tablePrinter.AddColumn("yc", 4);
    tablePrinter.AddColumn("rc", 4);
}

void Database::create_database()
{
    ofstream fout;
    fout.open(TEAM);
    fout.close();
}

void Database::save_database()
{
    ofstream fout;
    fout.open(TEAM);
    for(int i = 0; i < this->players.size(); i++)
    {
        fout << "\"" << this->players[i].getID() << "\" ";
        fout << "\"" << this->players[i].get_name() << "\" ";
        fout << "\"" << this->players[i].get_birthday() << "\" ";
        fout << "\"" << this->players[i].get_number() << "\" ";
        fout << "\"" << this->players[i].get_games() << "\" ";
        fout << "\"" << this->players[i].get_assists() << "\" ";
        fout << "\"" << this->players[i].get_goals() << "\" ";
        fout << "\"" << this->players[i].get_yc() << "\" ";
        fout << "\"" << this->players[i].get_rc() << "\"\n";
    }
    fout.close();
}

void Database::add_player()
{
    Player player;
    string name;
    string birthday;
    string number;
    int games, assists, goals, yc, rc;

    cout << "Name: ";
    cin >> name;
    cout << "Birthday: ";
    cin >> birthday;
    cout << "Number: ";
    cin >> number;
    cout << "Games: ";
    games = protect.protect();
    cout << "Assists: ";
    assists = protect.protect();
    cout << "Goals: ";
    goals = protect.protect();
    cout << "Yellow cards: ";
    yc = protect.protect();
    cout << "Red cards: ";
    rc = protect.protect();

    player.setID(this->players.size());
    player.set_name(name);
    player.set_birthday(birthday);
    player.set_number(number);
    player.set_games(games);
    player.set_assists(assists);
    player.set_goals(goals);
    player.set_yc(yc);
    player.set_rc(rc);
    this->players.push_back(player);
    save_database();
}

void Database::delete_player()
{
    string buffer = "";
    cout << "Enter name of player: ";
    try
    {
        cin >> buffer;
        if(this->looking_for_player(buffer) < 0)
        {
            throw 1;
        }
        this->players.erase(this->players.begin() + this->looking_for_player(buffer));
        cout << "This player has been successfully deleted!\n";
        this->save_database();
    }
    catch(...)
    {
        cout << "Such player doesn't exist.\n";
    }
}


void Database::view_all_players()
{
    TablePrinter tablePrinter(&std::cout);
    if(this->players.size() == 0)
    {
        cout << "Database of players is empty!" << std::endl;
    }
    else {
        this->head(tablePrinter);
        tablePrinter.PrintHeader();
        for (int i = 0; i < this->players.size(); i++) {
            tablePrinter << this->players[i].getID() << this->players[i].get_name() << this->players[i].get_birthday()
                         << this->players[i].get_number() << this->players[i].get_games()
                         << this->players[i].get_assists() << this->players[i].get_goals()
                         << this->players[i].get_yc() << this->players[i].get_rc();
        }
        tablePrinter.PrintFooter();
    }
}

int Database::looking_for_player(string name)
{
    for(int i = 0; i < this->players.size(); i++)
    {
        if(this->players[i].get_name() == name)
        {
            return i;
        }
    }
    return -1;
}

void Database::show_player(int i)
{
    TablePrinter tablePrinter(&std::cout);
    this->head(tablePrinter);
    tablePrinter << this->players[i].getID() << this->players[i].get_name() << this->players[i].get_birthday()
                 << this->players[i].get_number() << this->players[i].get_games()
                 << this->players[i].get_assists() << this->players[i].get_goals()
                 << this->players[i].get_yc() << this->players[i].get_rc();
}

void Database::check_player(int index)
{
    Player player;
    TablePrinter tablePrinter(&std::cout);
    this->head(tablePrinter);
    tablePrinter.PrintHeader();
    this->show_player(index);
    tablePrinter.PrintFooter();
}

void Database::change_player()
{
    string new_name, new_birthday;
    string new_number;
    int new_games, new_assists, new_goals, new_yc, new_rc;
    Player player;
    int numberr;

    cout << "Enter the list number of player: ";
    numberr = this->protect.protect();
    cout << "Your player is:\n";
    this->check_player(numberr);

    cout << "Name: ";
    cin >> new_name;
    cout << "Birthday: ";
    cin >> new_birthday;
    cout << "Number: ";
    cin >> new_number;
    cout << "Games: ";
    new_games = protect.protect();
    cout << "Assists: ";
    new_assists = protect.protect();
    cout << "Goals: ";
    new_goals = protect.protect();
    cout << "Yellow cards: ";
    new_yc = protect.protect();
    cout << "Red cards: ";
    new_rc = protect.protect();

    this->players[numberr].set_name(new_name);
    this->players[numberr].set_birthday(new_birthday);
    this->players[numberr].set_number(new_number);
    this->players[numberr].set_games(new_games);
    this->players[numberr].set_assists(new_assists);
    this->players[numberr].set_goals(new_goals);
    this->players[numberr].set_yc(new_yc);
    this->players[numberr].set_rc(new_rc);

    this->save_database();
    cout << "Your player after editing:\n";
    this->check_player(numberr);
}



void Database::search_mode()
{
    int choice;
    cout << "Choose searching\n";
    cout << "1.By name\n";
    cout << "2.By birthday\n";
    cout << "3.By number\n";
    cout << "0.EXIT\n";
    cout << "Just choose the number: ";
    choice = this->protect.protect();
    switch(choice)
    {
        case 1:
            this->search_name_mode();
            break;
        case 2:
            this->search_birthday_mode();
            break;
        case 3:
            this->search_number_mode();
            break;
        default:
            return;
    }
}

vector<int> Database::search_a_player(int key, string keyword)
{
    switch(key)
    {
        case SEARCHNAME:
            return this->search_by_name(keyword);
        case SEARCHBIRHDAY:
            return this->search_by_birthday(keyword);
        case SEARCHNUMBER:
            return  this->search_by_number(keyword);
        default:
           cout << "Error!\n";
    }
}

vector<int> Database::search_by_name(string key)
{
    vector<int> findName;
    for(int i = 0; i < this->players.size(); i++)
    {
        if(this->players[i].isName(key))
        {
            findName.push_back(i);
        }
    }
    if(findName.size() == 0)
    {
        cout << "Player with such name doesn't exist.\n";
    }
    else
    {
        return findName;
    }
}

vector<int> Database::search_by_birthday(string key)
{
    vector<int> findBirthday;
    for(int i = 0; i < this->players.size(); i++)
    {
        if(this->players[i].isBirthday(key))
        {
            findBirthday.push_back(i);
        }
    }
    if(findBirthday.size() == 0)
    {
        cout << "Player with such birthday doesn't exist.\n";
    }
    else
    {
        return findBirthday;
    }
}

vector<int> Database::search_by_number(string key)
{
    vector<int> findNumber;
    for(int i = 0; i < this->players.size(); i++)
    {
        if(this->players[i].isNumber(key))
        {
            findNumber.push_back(i);
        }
    }
    if(findNumber.size() == 0)
    {
        cout << "Player with such number doesn't exist.\n";
    }
    else
    {
        return findNumber;
    }
}

void Database::search_name_mode()
{
    string name;
    cout << "Enter name: ";
    cin >> name;
    vector<int> nameSearch = this->search_a_player(SEARCHNAME, name);
    this->show_records(nameSearch);

}

void Database::search_birthday_mode()
{
    string birthday;
    cout << "Enter birthday: ";
    cin >> birthday;
    vector<int> birthdaySearch = this->search_a_player(SEARCHBIRHDAY, birthday);
    this->show_records(birthdaySearch);
}

void Database::search_number_mode()
{
    string number;
    cout << "Enter number: ";
    cin >> number;
    vector<int> numberSearch = this->search_a_player(SEARCHNUMBER, number);
    this->show_records(numberSearch);
}

void Database::show_records(vector<int> &findMe)
{
    TablePrinter tablePrinter(&std::cout);
    this->head(tablePrinter);
    tablePrinter.PrintHeader();
    for(int i = 0; i < findMe.size(); i++)
    {
        this->show_player(findMe[i]);
    }
    tablePrinter.PrintFooter();
}

void Database::sort_mode()
{
    int choice;
    cout << "Choose sorting\n";
    cout << "1.By games\n";
    cout << "2.By assists\n";
    cout << "3.By goals\n";
    cout << "Just choose the number: ";
    choice = this->protect.protect();
    switch(choice)
    {
        case 1:
            this->sortPlayersBy(SORTGAMES);
            this->view_all_players();
            break;
        case 2:
            this->sortPlayersBy(SORTASSISTS);
            this->view_all_players();
            break;
        case 3:
            this->sortPlayersBy(SORTGOALS);
            this->view_all_players();
            break;
        default:
            return;
    }
}

void Database::sortPlayersBy(int key)
{
    switch(key)
    {
        case SORTGAMES:
            this->sortGames(0, this->players.size() - 1);
            break;
        case SORTASSISTS:
            this->sortAssists(0, this->players.size() - 1);
            break;
        case SORTGOALS:
            this->sortGoals(0, this->players.size() - 1);
            break;
        default:
            cout << "Error!\n";
    }
}

void Database::sortGames(int left, int right) {
    int i = left, j = right;
    Player tmp;
    int variable = this->players[(left + right) / 2].get_games();

    while (i <= j)
    {
        while (this->players[i].get_games() < variable)
            i++;
        while (this->players[j].get_games() > variable)
            j--;
        if (i <= j)
        {
            tmp = this->players[i];
            this->players[i] = this->players[j];
            this->players[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j)
        this->sortGames(left, j);
    if (i < right)
        this->sortGames(i, right);
}

void Database::sortAssists(int left, int right)
{
    int i = left, j = right;
    Player tmp;
    int variable = this->players[(left + right) / 2].get_assists();

    while (i <= j) {
        while (this->players[i].get_assists() < variable)
            i++;
        while (this->players[j].get_assists() > variable)
            j--;
        if (i <= j) {
            tmp = this->players[i];
            this->players[i] = this->players[j];
            this->players[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j)
        sortAssists(left, j);
    if (i < right)
        sortAssists(i, right);
}

void Database::sortGoals(int left, int right)
{
    int i = left, j = right;
    Player tmp;
    int variable = this->players[(left + right) / 2].get_goals();

    while (i <= j) {
        while (this->players[i].get_goals() < variable)
            i++;
        while (this->players[j].get_goals() > variable)
            j--;
        if (i <= j) {
            tmp = this->players[i];
            this->players[i] = this->players[j];
            this->players[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j)
        sortGoals(left, j);
    if (i < right)
        sortGoals(i, right);
}

void Database::show_rc()
{
    TablePrinter tablePrinter(&std::cout);
    this->head(tablePrinter);
    tablePrinter.PrintHeader();
    for(int i = 0; i < this->players.size(); i++)
    {
        if(this->players[i].get_rc() > 0)
        {
            tablePrinter << this->players[i].get_name() << this->players[i].get_birthday()
                         << this->players[i].get_number() << this->players[i].get_games()
                         << this->players[i].get_assists() << this->players[i].get_goals()
                         << this->players[i].get_yc() << this->players[i].get_rc();
        }
    }
    tablePrinter.PrintFooter();
}

void Database::show_best_players()
{
    TablePrinter tablePrinter(&std::cout);
    vector<int> best;
    this->head(tablePrinter);
    tablePrinter.PrintHeader();
    for(int i = 0; i < this->players.size(); i++)
    {
        best.push_back(this->players[i].get_assists() + this->players[i].get_goals());

    }
    for_best_players(0, this->players.size(), best, players);
    for(int i = 0; i < this->players.size(); i++)
    {
        tablePrinter << this->players[i].get_name() << this->players[i].get_birthday()
                     << this->players[i].get_number() << this->players[i].get_games()
                     << this->players[i].get_assists() << this->players[i].get_goals()
                     << this->players[i].get_yc() << this->players[i].get_rc();
    }
    tablePrinter.PrintFooter();
}

void Database::for_best_players(int left, int right, vector<int> &v, vector<Player> &db)
{
    Player tmp;
    int i = left, j = right;
    int temp = 0;
    int variable = v[(left+right) / 2];
    while(i <= j)
    {
        while(v[i] > variable)
            i++;
        while(v[j] < variable)
            j--;
        if(i <= j)
        {
            tmp = db[i];
            db[i] = db[j];
            db[j] = tmp;
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
        if(left < j)
        {
            for_best_players(left, j, v, db);
        }
        if(i == right)
        {
            for_best_players(i, right, v, db);
        }
    }
}
