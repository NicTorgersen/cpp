// man307
// 6.5

#include <iostream>
#include <vector>
using namespace std;

class Account {
    private:
        string account_name;
        double balance;
        bool is_credit;
    public:
        string get_name() {
            return account_name;
        }
        double get_balance() {
            return balance;
        }
        bool get_credit() {
            return is_credit;
        }
        void change_balance(double amount) {
            balance = balance + amount;
        }
        /* The constructor is defined as follows:
        Account(string, bool);
        */
        void constructor( string, bool );
};

class Bank {
    // Private or public?
    vector<Account> accounts;
    // Indentation
    public:
    void create_account(Account);
    void remove_account(int);
    void transaction(int, double);
    void get_accounts();

    bool verify_account(string);
    int get_position(string);

    double get_balance(int);
    bool get_credit(int);
};

class BankPrinter {
    private:
        Bank bank;
    public:
        BankPrinter(Bank);
        void print_accounts();
};

void BankPrinter

void Account::constructor( string name, bool credit ) {
    is_credit = credit;
    account_name = name;
    balance = 0;
}

bool Bank::verify_account( string name ) {
    for ( int i=0 ; i<accounts.size() ; i++ ) {
        if ( accounts[i].get_name() == name ) {
                return true;
        }
    }
    return false;
}

int Bank::get_position( string name ) {
    for ( int i=0 ; i<accounts.size() ; i++ ) {
        if ( accounts[i].get_name() == name ) {
            return i;
        }
    }
}

double Bank::get_balance( int position ) {
    return accounts[position].get_balance();
}

bool Bank::get_credit( int position ) {
    return accounts[position].get_credit();
}

void Bank::create_account( Account account ) {
    accounts.push_back(account);
}

void Bank::remove_account( int position ) {
    accounts.erase( accounts.begin() + position );
}

void Bank::transaction( int position, double amount ) {
    accounts[position].change_balance(amount);
}

// Don't print from within your data.
void Bank::show_accounts() {
    cout << endl;
    double balance;

    for ( int i=0 ; i<accounts.size() ; i++) {
        balance = accounts[i].get_balance();
        cout << accounts[i].get_name() << " ";
        if ( balance == 0 ) {
            cout << "has no money on his account." << endl;
        }
        else if ( balance > 0) {
            cout << "owns " << balance << " euros." << endl;
        }
        else if ( balance < 0) {
            cout << "owes " << balance << " euros." << endl;
        }
    }
}

// This function is way too long.
// Remember you can and should make methods outside of your classes if needed.
// Function of the content of the while loop?
// Function of the contents of the if blocks?
int main() {
    string first_input;
    int line = 0;
    Bank bank;

    while ( cin >> first_input) {
        line++;

        if ( first_input == "c" ) {
            Account account;
            string name, yn;
            bool is_credit;

            cin >> name >> yn;
            if ( yn == "y" ) {
                is_credit = true;
            } else {
                is_credit = false;
            }
            bool account_exists = bank.verify_account ( name );
            if ( account_exists == false ) {
                account.constructor( name, is_credit );
                bank.create_account( account );
            } else {
                cerr << "error on line " << line << ": account already exists" << endl;
            }
        }

        else if (first_input == "t") {
            string name;
            double amount;
            cin >> name >> amount;

            bool account_exists = bank.verify_account ( name );
            if ( account_exists == true ) {
                int position = bank.get_position ( name );
                double balance = bank.get_balance ( position );
                bool is_credit = bank.get_credit ( position );
                if ( is_credit == false && (balance+amount)<0 ) {
                    cerr << "error on line " << line << ": account cannot hold negative balance" << endl;
                } else {
                    bank.transaction( position, amount );
                }
            } else {
                cerr << "error on line " << line << ": account does not exist" << endl;
            }
        }

        else if (first_input == "r") {
            string name;
            cin >> name;

            bool account_exists = bank.verify_account ( name );
            if ( account_exists == true ) {
                int position = bank.get_position ( name );
                double balance = bank.get_balance ( position );
                if ( balance > 0 ){
                    bank.remove_account ( position );
                } else {
                    cerr << "error on line " << line << ": account holds negative balance" << endl;
                }
            } else {
                cerr << "error on line " << line << ": account does not exist" << endl;
            }
        }
    }
    // Manually retrieve the bank accounts one-by-one and print their content.
    bank.show_accounts();

    return 0;
}
