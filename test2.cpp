#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int i= 0;
    int input;
    vector<int> list;

    cout << "Please enter your list of numbers (enter a non-integer when you wish for the list to end or ctrl + D: ";

    try {
        while (cin >> input){
            list.push_back(input);
        }

        sort(list.begin(), list.end());

        if (list[0] == list[list.size()-1]) {
            throw std::runtime_error("input mismatch");
        } else {
            while (list[i] == list[0]) {
                i++;
            }

            cout << "The second smallest number is " << list[i] << endl;
        }
    }
    catch(runtime_error) {
        cout << "error no smallest number" << endl;
    }

    for (int n = 0; n < list.size(); n++) {
        cout << list[n] << " ";
    }
    
    cout<< endl << i+1 << endl;

    return 0;
}
