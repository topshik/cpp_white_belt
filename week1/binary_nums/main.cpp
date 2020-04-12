#include <iostream>
#include <vector>

int main() {
    int num;
    std::cin >> num;
    std::vector<int> bin_num;
    while (num != 0) {
        bin_num.push_back(num % 2);
        num = num / 2;
    }

    for (size_t i = bin_num.size() - 1; i != -1; --i) {
        std::cout << bin_num[i];
    }
    return 0;
}
