//
// Created by kristianshevando on 10.5.17.
//

#include "Player.h"


Player::Player()
{
}

void Player::setID(int id)
{
   this->id = id;
}

void Player::set_name(string name)
{
   this->name = name;
}

void Player::set_birthday(string birthday)
{
   this->date.setDate(birthday);
}

void Player::set_number(string number)
{
   this->number = number;
}

void Player::set_games(int games)
{
   this->games = games;
}

void Player::set_assists(int assists)
{
   this->assists = assists;
}

void Player::set_goals(int goals)
{
   this->goals = goals;
}

void Player::set_yc(int yc)
{
   this->yc = yc;
}

void Player::set_rc(int rc)
{
   this->rc = rc;
}

int Player::getID()
{
   return this->id;
}

string Player::get_name()
{
   return this->get_name2();
}

string Player::get_birthday()
{
    return this->date.getString();
}

string Player::get_number()
{
   return this->number;
}

int Player::get_games()
{
   return this->games;
}

int Player::get_assists()
{
   return this->assists;
}

int Player::get_goals()
{
   return this->goals;
}

int Player::get_yc()
{
   return this->yc;
}

int Player::get_rc()
{
   return this->rc;
}

string Player::get_name2()
{
   return this->name;
}


bool Player::isName(string key)
{
   return this->get_name2() == key;
}

bool Player::isBirthday(string key)
{
   return this->get_birthday() == key;
}

bool Player::isNumber(string key)
{
   return this->get_number() == key;
}