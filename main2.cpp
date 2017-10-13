#include <iostream>
#include <vector>
using namespace std;

void diviseAndPrint (int d, vector<int> v) {
    cout << "The updated list is: \t\t";
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] % d == 0) {
            v[i]++;
        }
        cout << v[i];
    }
}

int main () {
    char currInput;
    int divisor;
    vector<int> list;

    cout << "Enter the divisor: \t\t";
    cin >> divisor;

    cout << "Enter the list to be updated: \t";

    do {
        cin >> currInput;

        if (currInput > 48 && currInput < 58) {
            list.push_back( ((int) currInput - 48) );
        }

    } while (currInput != '\\');

    diviseAndPrint(divisor, list);
}
