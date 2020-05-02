#include <fstream>
#include <iomanip>
#include <iostream>

int main() {
    std::ifstream input("input.txt");
    if (input) {
        std::string n, m, num;
        std::getline(input, n, ' ');
        std::getline(input, m);
        for (size_t i = 0; i != stoi(n); ++i) {
            for (size_t j = 0; j != stoi(m) - 1; ++j) {
                std::getline(input, num, ',');
                std::cout << std::setw(10) << num << ' ';
            }
            std::getline(input, num);
            std::cout << std::setw(10) << num;
            if (i != stoi(n) - 1) {
                std::cout << std::endl;
            }
        }
    }
    return 0;
}
