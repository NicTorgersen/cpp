#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int input = 0;
    vector<int> num_list; // = {34, 254, 1, -5, -13};

    cout << "Enter the numbers in random order: ";
    cin >> num_list;

    if (cin.fail()) {
        cout << "error: invalid input";
        return 0;
    }

    sort(num_list.begin(), num_list.end());

    if (num_list.size() < 1) {
        cout << "error: invalid input length";
        return 0;
    }

    for (int i = 0; i < num_list.size(); i++) {
        if (i != 0) {
            
        }
    }

    cout << num_list[1];

    return 0;
}
