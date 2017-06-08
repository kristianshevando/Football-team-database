
//
// Created by kristianshevando on 21.5.17.
//

#include "Account.h"

using namespace std;

void Account::setlog(string buffer)
{
   this->login = buffer;
}

void Account::setpass(string buffer)
{
   this->password = buffer;
}

void Account::setrole(string buffer)
{
   if(buffer == "admin")
   {
      this->isAdmin = true;
   }
   else
   {
       this->isAdmin = false;
   }
}

string Account::getlog()
{
   return this->login;
}

string Account::getpas()
{
   return this->password;
}

string Account::admin_or_user()
{
    if (this->isAdmin)
    {
        return "admin";
    }
    else
    {
        return "user";
    }
}
