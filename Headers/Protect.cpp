//
// Created by kristianshevando on 10.5.17.
//

#include "Protect.h"

int Protect::protect()
{
    string buffer = "";
    int normal = 0;
    cin >> buffer;
    try
    {
       normal = stoi(buffer);
       if(normal < 0)
       {
           throw 1;
       }
       return normal;
    }
    catch(...)
    {
       cout << "Wrong input!!!\nTry again: ";
       return protect();
    }

}
