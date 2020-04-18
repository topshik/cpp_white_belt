#include <iostream>
#include <set>

int main() {
    std::set<std::string> strings;
    std::string curr_str;
    int n;
    std::cin >> n;
    for (size_t i = 0; i != n; ++i) {
        std::cin >> curr_str;
        strings.insert(curr_str);
    }
    std::cout << strings.size() << std::endl;
    return 0;
}
