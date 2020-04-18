#include <iostream>
#include <set>
#include <map>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string> some_map) {
    std::set<std::string> res;
    for (const auto& [key, value] : some_map) {
        res.insert(value);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
