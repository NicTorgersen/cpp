#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int input = 0, i = 0;
    vector<int> list;
    cout << "Please enter your list of numbers: ";
    cin >> input;

    while (!cin.fail()){
        list.push_back(input);
        cin >> input;
    }
    sort(list.begin(), list.end());
    if (list[0] == list[list.size()-1]) {
        cout << "There is no smallest number." << endl;
    } else {
        while (list[i] == list[0]) {
            i = i++;
        }
        cout << "The second smallest number is " << list[i] << endl;
    }

    for (int n = 0; n < list.size(); n++) {
        cout << list[n] << endl;
    }

    return 0;
}
