#include <iostream>

int main() {
    double n, a, b, x, y;
    std::cin >> n >> a >> b >> x >> y;
    if (n > b) {
        std::cout << n * (100 - y) / 100;
        return 0;
    }
    if (n > a) {
        std::cout << n * (100 - x) / 100;
        return 0;
    }
    std::cout << n;
    return 0;
}
