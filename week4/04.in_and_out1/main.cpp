#include <fstream>
#include <iostream>

int main() {
    std::ifstream input("input.txt");
    if (input) {
        std::string line;
        while(std::getline(input, line)) {
            std::cout << line << std::endl;
        }
    }
    return 0;
}
