#ifndef BANK_H
#define BANK_H
#include <Account.h>
#include <vector>


class Bank
{
    public:
        Bank(std::vector<Account>);

        void addAccount(Account);

        std::vector<Account> getAccounts();

        Account getAccount(int);
        Account getAccount(std::string);

    protected:

    private:
        std::vector<Account> accounts;
};

#endif // BANK_H
