#include <iostream>
#include <vector>
using namespace std;

// https://projecteuler.net/problem=1
int main () {
    int iter, x, y, sum, should_print;
    vector<int> nums;
    x = 3;
    y = 5;
    sum = 0;
    should_print = 0;

    cout << "Enter how many loops (<): ";
    cin >> iter;
    cout << "Should I print all the multiples of 3 and 5? (1/0) ";
    cin >> should_print;

    for (int i = 1; i < iter; i++) {
        if (i % x == 0 || i % y == 0) {
            nums.push_back(i);
        }
    }

    if (should_print) {
        cout << "The multiples are: \t";
    }

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (should_print) {
            cout << nums[i];

            if (i == (nums.size() - 2)) {
                cout << " and ";
            } else if (i != (nums.size() - 1)) {
                cout << ", ";
            }
        }
    }

    cout << endl << "The sum is: \t\t" << sum;
}
