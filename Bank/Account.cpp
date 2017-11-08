#include "Account.h"
#include <string>

using namespace std;

Account::Account(int num, string acName, int acBalance, bool acIsCredit)
{
    number = num;
    name = acName;
    balance = acBalance;
    isCredit = acIsCredit;
}
Account::Account(int num, string acName, int acBalance)
{
    number = num;
    name = acName;
    balance = acBalance;
}
Account::Account(string acName, int acBalance, bool acIsCredit)
{
    name = acName;
    balance = acBalance;
    isCredit = acIsCredit;
}
Account::Account(string acName, int acBalance)
{
    name = acName;
    balance = acBalance;
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
