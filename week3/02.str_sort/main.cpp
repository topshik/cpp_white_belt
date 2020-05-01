#include <algorithm>
#include <iostream>
#include <vector>

bool Comp(std::string a, std::string b) {
    for (auto& c : a) {
        c = std::tolower(c);
    }
    for (auto& c : b) {
        c = std::tolower(c);
    }
    return a <= b;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> strings(n);
    for (size_t i = 0; i != n; ++i) {
        std::cin >> strings[i];
    }
    std::sort(strings.begin(), strings.end(), Comp);
    for (size_t i = 0; i != n; ++i) {
        std::cout << strings[i] << ' ';
    }
    return 0;
}
