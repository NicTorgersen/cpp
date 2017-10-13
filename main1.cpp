#include <iostream>   // std::cout
#include <string>     // std::string, std::stod

int main () {
    int marksToAdd;
    std::string marks = "";

    std::cin >> marksToAdd;

    for (int i = 0; i < marksToAdd; i++) {
        marks += "! ";
    }

    std::cout << marks;
}
