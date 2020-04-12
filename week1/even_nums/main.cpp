#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    for (size_t i = a; i != b + 1; ++i) {
        if (i % 2 == 0) {
            std::cout << i << ' ';
        }
    }
    return 0;
}
