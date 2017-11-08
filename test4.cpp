#include <iostream>
#include <string>
#include <vector>

void my_sort (std::vector<std::string> list) {

    for (int i = 0; i < sizeof(list); i++) {
        for (int j = 0; j < sizeof(list) - 1; j++) {
            std::string current_element = list[j];
            std::string next_element = list[j+1];

            std::cout << current_element << "\t->\t";
            std::cout << next_element << std::endl << std::endl;

            if (current_element > next_element) {
                swap(list[j], list[j+1]);
                /*
                list[j-1] = list[j];
                list[j] = list[j+1];
                */
            }
        }
    }
}

int main () {
    // std::string list[4] = {"E001", "E201", "E101", "E210"};
    std::vector<std::string> list = {"E001", "E201", "E101", "E210"};

    my_sort(list);
    for (int i = 0; i < 4; i++) {
        std::cout << list[i] << std::endl;
    }
}
