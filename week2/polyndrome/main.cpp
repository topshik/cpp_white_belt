#include <iostream>

bool IsPalindrom(const std::string &str) {
    int length = str.size();
    for (size_t i = 0; i != length / 2; ++i) {
        if (str[i] != str[length - i - 1]) return false;
    }
    return true;
}

int main() {
    std::string str;
    std::cin >> str;
    std::cout << IsPalindrom(str);
    return 0;
}
