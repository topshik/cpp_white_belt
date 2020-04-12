#include <cmath>
#include <iostream>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
    if (a == 0) {
        if (b != 0) {
            std::cout << -c / b;
            return 0;
        } else {
            std::cout << std::endl;
            return 0;
        }
    }
    double disc = b * b - 4 * a * c;
    if (disc == 0) {
        std::cout << (-b + std::sqrt(disc)) / (2 * a);
        return 0;
    } else if (disc > 0){
        std::cout << (-b + std::sqrt(disc)) / (2 * a) << ' ' << (-b - std::sqrt(disc)) / (2 * a);
        return 0;
    } else {
        std::cout << std::endl;
        return 0;
    }
}
