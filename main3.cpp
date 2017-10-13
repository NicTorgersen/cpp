#include <iostream>
#include <vector>

int main () {
    int input;
    int n;        //divisor
    std::vector<int> list;

    std::cout << "Enter the divisor: ";
    std::cin >> n;
    std::cout << "Enter the list to be updated: ";

    if (isdigit(29)) {
        std::cout << 29 << " is a digit.";
    }

    do {
        std::cin >> input;
        if (input != 0) {
            list.push_back(input);
        }
    } while (input);

    for (int i = 0; i < list.size(); i++) {
        if (list[i] % n == 0) {
            list[i]++;
        }

        std::cout << list[i] << std::endl;
    }
    return 0;
}
