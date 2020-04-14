#include <iostream>
#include <vector>

bool IsPalindrom(const std::string &str) {
    int length = str.size();
    for (size_t i = 0; i != length / 2; ++i)
        if (str[i] != str[length - i - 1]) return false;
    return true;
}

std::vector<std::string> PalindromFilter(const std::vector<std::string>& candidates, int minLength) {
    std::vector<std::string> result;
    for (const std::basic_string<char>& cand : candidates)
        if (IsPalindrom(cand) && cand.size() >= minLength)
            result.push_back(cand);
    return result;
}

int main() {
    for (auto str : PalindromFilter({"kek", "lol", "cheburek"}, 2))
        std::cout << str << ' ';
    return 0;
}
