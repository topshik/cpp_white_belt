#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;
    bool flag1 = false;
    char ref_char = 'f';
    for (size_t i = 0; i != str.size(); ++i) {
        if (str[i] == ref_char) {
            if (flag1) {
                std::cout << i;
                return 0;
            } else {
                flag1 = true;
            }
        }
    }
    if (flag1) {
        std::cout << -1;
        return 0;
    }
    std::cout << -2;
    return 0;
}
