#ifndef INTROW_H
#define INTROW_H


class IntRow
{
    public:
        IntRow();
        ~IntRow();
        int at(int);
        void push_back(int);
        int length();

    protected:

    private:
        int *elements;
        int size;
};

#endif // INTROW_H
