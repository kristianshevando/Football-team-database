//
// Created by kristianshevando on 20.5.17.
//

#include "Authorization.h"

Authorization::Authorization()
{
    this->read_db();
}

void Authorization::read_db()
{
    std::ifstream fin;
    fin.open(ACCOUNTS);
    if(!fin.is_open())
    {
        cout << "File doesn't exist. This file and account will be created by default.\n";
        this->create_db_default();
        this->create_fa_default();
    }
    std::string buffer = "";
    while(fin.peek()!=EOF)
    {
       getline(fin, buffer);
       this->accounts.push_back(this->for_read_db(buffer));
    }
    if(this->accounts.size() == 0)
    {
        cout << "There is no accounts in file. Create it!\n";
        this->create_fa_default();
    }
}

Account Authorization::for_read_db(std::string st)
{
   Account account;
   std::string str = "";
   vector<std::string> strings(0);
    for(int i = 0; i < st.size(); i++)
    {
        if(st[i] == '\"')
        {
            i++;
            while(true)
            {
                str += st[i];
                i++;
                if(st[i] == '\"')
                {
                    strings.push_back(str);
                    str = "";
                    break;
                }
            }
        }
    }
    account.setlog(strings[LOGIN]);
    account.setpass(strings[PASSWORD]);
    account.setrole(strings[ROLE]);

    return account;
}

void Authorization::create_account()
{

    std::string login;
    std::string password;
    std::string role;

    std::cout << "Create login: ";
    std::cin >> login;
    if(login == "exit" || login == "Exit")
    {
        std::cout << "Sorry, you can't create such login.\n";
        std::cout << "Try to come up with something different.\n";
        this->create_account();
        return void();
    }
    std::cout << "Create password: ";
    std::cin >> password;
    std::cout << "Say the role(admin/user): ";
    std::cin >> role;

    if(this->looking_for_account(login) > -1)
    {
       cout << "This login is already taken.\n";
       cout << "Try to come up with something different.\n";
       this->create_account();
    }

    this->account.setlog(login);
    this->account.setpass(password);
    this->account.setrole(role);
    this->accounts.push_back(account);
    this->save_account();
}

void Authorization::save_account()
{
   std::ofstream fout;
   fout.open(ACCOUNTS);
   for(int i = 0; i < this->accounts.size(); i++)
   {
       fout << "\"" << this->accounts[i].getlog() << "\" ";
       fout << "\"" << this->accounts[i].getpas() << "\" ";
       fout << "\"" << this->accounts[i].admin_or_user() << "\"\n";
   }
   fout.close();
}

string Authorization::come_in()
{
   Admin admin;
   User user;
   std::string login = "";
   std::string password = "";
   bool is_ok = true;
   std::cout << "Enter 'exit' to EXIT\n";
   std::cout << "Enter login: ";
   std::cin >> login;
   if(login == "exit")
   {
       return "exit";
   }
   std::cout << "Enter password: ";
   std::cin >> password;
   for(int i = 0; i < this->accounts.size(); i++)
   {
       if(this->accounts[i].getlog() == login)
       {
           if(this->accounts[i].getpas() == password)
           {
               if(this->accounts[i].admin_or_user() == "admin")
               {
                   admin.Admin_Mode();
                   return "admin";
               }
               else
               {
                   user.User_Mode();
                   return "user";
               }
           }
           else
           {
               is_ok = false;
           }
       }
       else
       {
           is_ok = false;
       }
   }
   if(!is_ok)
   {
        std::cout << "login or password incorrect!\n";
        return this->come_in();
   }
}

void Authorization::create_db_default()
{
   std::ofstream fout;
   fout.open(ACCOUNTS);
   fout.close();
}

void Authorization::create_fa_default()
{
   this->create_account();
}

int Authorization::looking_for_account(std::string login)
{
   for(int i = 0; i < this->accounts.size(); i++)
   {
       if(this->accounts[i].getlog() == login)
       {
           return i;
       }
   }
   return -1;
}

void Authorization::delete_account()
{
   std::string buffer = "";
   std::cout << "Enter login: ";
   try
   {
       cin >> buffer;
       if(this->looking_for_account(buffer) < 0)
       {
           throw 1;
       }
       this->accounts.erase(this->accounts.begin() + this->looking_for_account(buffer));
       std::cout << "This account has been successfully deleted!\n";
       this->save_account();
   }
   catch(...)
   {
       std::cout << "Account doesn't exist.\n";
   }
}


void Authorization::watch_accounts()
{
    TablePrinter tablePrinter(&std::cout);
    tablePrinter.AddColumn("Login", 20);
    tablePrinter.AddColumn("Status", 20);
    tablePrinter.PrintHeader();
    for(int i = 0; i < this->accounts.size(); i++)
    {
        tablePrinter << this->accounts[i].getlog() << this->accounts[i].admin_or_user();
    }
    tablePrinter.PrintFooter();
}

