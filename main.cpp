#include "Headers/Admin.h"
#include "Headers/User.h"
#include "Headers/Protect.h"
#include "Headers/Authorization.h"


int logInMenu();

int main()
{
    logInMenu();
    return 0;
}

int logInMenu()
{
    Authorization authorization;
    Protect protect;
    string buffer;
    std::cout << "1.ENTER\n0.EXIT\n";
    std::cout << "Just choose the number: ";
    int choice = protect.protect();
    switch (choice)
    {
        case 1:
            while(true)
            {
                buffer = authorization.come_in();
                if(buffer == "admin")
                {
                    Admin admin;
                }
                else if(buffer == "user")
                {
                    User user;
                }
                else
                {
                    break;
                }
            }
        default:
            return 0;
    }
}