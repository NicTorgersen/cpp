#include "Account.h"
#include <string>

using namespace std;

Account::Account(int num, string acName, int balance)
{
    num = num;
    name = acName;
    balance = balance;
}
Account::Account(string acName, int balance)
{
    name = acName;
    balance = balance;
}
Account::Account(string acName)
{
    name = acName;
    balance = 0;
}

void Account::setName(string acName)
{
    name = acName;
}
string Account::getName()
{
    return name;
}

void Account::incrementBalance(int amount)
{
    balance += amount;
}
void Account::decrementBalance(int amount)
{
    balance -= amount;
}
int Account::getBalance()
{
    return balance;
}

int Account::getNumber()
{
    return number;
}
