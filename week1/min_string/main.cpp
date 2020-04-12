#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string a, b, c;
    std::cin >> a >> b >> c;
    std::cout << std::min(std::min(a, b), c) << std::endl;
    return 0;
}
