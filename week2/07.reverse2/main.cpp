#include <iostream>
#include <vector>

std::vector<int> Reversed(std::vector<int> v) {
    for (size_t i = 0; i != v.size() / 2; ++i) {
        std::swap(v[i], v[v.size() - 1 - i]);
    }
    return v;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
