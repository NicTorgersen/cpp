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
    for (vector<Account>::iterator account = accounts.begin(); account != accounts.end(); ++account)
    {
        if (account->getNumber() == number)
        {
            return *account;
        }
    }
}
Account Bank::getAccount(string name)
{
    for (vector<Account>::iterator account = accounts.begin(); account != accounts.end(); ++account)
    {
        cout << account->getNumber() << endl;
        if (account->getName() == name)
        {
            return *account;
        }
    }
}
