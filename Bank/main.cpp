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
        name += c++;
    }

    return name;
}

void fileOperations (string filename)
{

}

int main()
{
    bool running = true;
    vector<Account> accs;

    for (int i = 0; i < 5; i++)
    {
        string name = generate_name(i, 3);
        Account acc(i+1, name, 0, false);
        accs.push_back(acc);
        cout << "Added " << acc.getName() << " to ledger." << endl;
    }

    Bank b(accs);

    cout << "Welcome to Bank-o-matic 3000" << endl;
    cout << "Type 'h' for help.\n\n";

    while(running)
    {
        cout << "> ";

        char in;
        cin >> in;

        switch(in)
        {
            case 'h': { // help
                cout << "Type 'l' to list all accounts.\nType 'a' to add money to account number.\nType 'r' to read from a file.\nType 'c' to close." << endl;
                break;
            }

            case 'l': { // list
                b.listAccounts();
                break;
            }

            case 'a': { // add money
                cout << "Enter account number\n" << "> ";
                int accountNumber;
                cin >> accountNumber;

                cout << "Enter amount\n" << "> ";
                int amount;
                cin >> amount;

                break;
            }

            case 'r': { // read from file
                cout << "Please provide a filename (txt file): ";
                string filename;
                cin >> filename;
                break;
            }

            case 'g': {
                cout << "Please provide the account number: ";
                int accountNumber;
                cin >> accountNumber;
                Account acc = b.getAccount(accountNumber);
                cout << "Thank you. Here is what we could find for " << accountNumber << endl;

            }

            case 'c': { // close
                cout << "Thanks for using Bank-o-matic 3000.\nHave a nice day." << endl;
                running = false;
                break;
            }

        }
    }

    return 0;
}
