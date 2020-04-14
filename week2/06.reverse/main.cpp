#include <iostream>
#include <vector>

void Reverse(std::vector<int>& v) {
    for (size_t i = 0; i != v.size() / 2; ++i) {
        std::swap(v[i], v[v.size() - 1 - i]);
    }
}

int main() {
    std::vector<int> a = {1, 2, 3};
    Reverse(a);
    for (auto elem : a)
        std::cout << elem << std::endl;
    return 0;
}
