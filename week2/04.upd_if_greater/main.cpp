#include <iostream>

void UpdateIfGreater(int first, int& second) {
    if (first > second)
        second = first;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
