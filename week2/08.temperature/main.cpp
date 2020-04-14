#include <iostream>
#include <vector>

std::vector<int> filter_by_mean(const std::vector<int>& temperatures) {
    int mean = 0;
    for (size_t i = 0; i != temperatures.size(); ++i)
        mean += temperatures[i];
    mean /= temperatures.size();
    std::vector<int> result;
    for (size_t i = 0; i != temperatures.size(); ++i)
        if (temperatures[i] > mean)
            result.push_back(i);
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> temperatures(n);
    for (size_t i = 0; i != n; ++i)
        std::cin >> temperatures[i];
    std::vector<int> filtered = filter_by_mean(temperatures);
    std::cout << filtered.size() << std::endl;
    for (auto num : filtered)
        std::cout << num << ' ';
    return 0;
}
