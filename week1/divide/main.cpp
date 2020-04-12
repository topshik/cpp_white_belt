#include <iostream>

int main() {
    double a, b;
    std::cin >> a >> b;
    if (b == 0) {
        std::cout << "Impossible";
    } else {
        std::cout << int(a / b);
    }
    return 0;
}
