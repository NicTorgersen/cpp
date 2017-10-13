#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bank.h"
#include "Account.h"

using namespace std;

string generate_name (int seed, int length)
{
    char c = seed + 65;
    string name = "";

    if (length > 6)
    {
        name += c;
        return name;
    }

    for (int i = 0; i < length; i++)
    {
        name += c;
    }

    return name;
}

int main()
{
    bool running = true;
    vector<Account> accs;
    for (int i = 0; i < 5; i++)
    {
        string name = generate_name(i, 3);
        Account acc(i, name, 0);
        accs.push_back(acc);
        cout << "Added " << acc.getName() << " to ledger." << endl;
    }
    Bank b(accs);

    cout << "Welcome to Bank-o-matic 3000" << endl;
    cout << "To start, type 'h'" << endl;
    // cout << "Welcome to Bank-o-matic 3000" << endl;

    while(running)
    {
        char in;
        cin >> in;
        switch(in)
        {
        case 'a': // add money
            int amount;
            cin >> amount;
            break;
        case 'h':
            cout << "Type a to add money to account number." << endl;

        }
    }

    return 0;
}
