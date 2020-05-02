#include <fstream>
#include <iomanip>
#include <iostream>

int main() {
    std::ifstream input("input.txt");
    if (input) {
        std::string num;
        while (std::getline(input, num)) {
            std::cout << std::fixed << std::setprecision(3) << stof(num) << std::endl;
        }
    }
    std::cout << std::endl;
    return 0;
}
