#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (size_t i = 0; i != n; ++i) {
        std::cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end(), [](int a, int b) {return std::abs(a) <= std::abs(b);});
    for (const auto& num : nums) {
        std::cout << num << ' ';
    }
    return 0;
}
