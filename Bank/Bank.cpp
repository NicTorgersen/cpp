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

void Bank::listAccounts()
{
    vector<Account> accs = getAccounts();
    for (int i = 0; i < accs.size(); i++)
    {
        cout << "--------------" << endl;
        cout << "Account name:\t\t" << accs[i].getName() << endl;
        cout << "Account number:\t\t" << accs[i].getNumber() << endl;
        cout << "Account balance:\t" << accs[i].getBalance() << endl;
        cout << "--------------" << endl;
    }
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
