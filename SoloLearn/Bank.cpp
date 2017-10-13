#include "Bank.h"
#include <iostream>
#include <vector>

using namespace std;

Bank::Bank(vector<Account> inAccounts)
{
    for (int i = 0; i < inAccounts.size(); i++)
    {
        accounts.push_back(inAccounts[i]);
    }
}

void Bank::addAccount(Account account)
{
    accounts.push_back(account);
}

vector<Account> Bank::getAccounts()
{
    return accounts;
}

Account Bank::getAccount(int number)
{
    for (vector<Account>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
    {
        if (iter->getNumber() == number)
        {
            return *iter;
        }
    }
}
Account Bank::getAccount(string name)
{
    for (vector<Account>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
    {
        if (iter->getName() == name)
        {
            return *iter;
        }
    }
}
