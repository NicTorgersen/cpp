#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account
{
    public:
        Account(int, std::string, int, bool);
        Account(int, std::string, int);
        Account(std::string, int);
        Account(std::string);

        void setName(std::string);
        std::string getName();

        void setNumber(int);
        int getNumber();

        void incrementBalance(int);
        void decrementBalance(int);
        int getBalance();

    protected:

    private:
        std::string name;
        int number;
        int balance;
        bool isCredit;
};

#endif // ACCOUNT_H
