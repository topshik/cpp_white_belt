#include <iostream>
#include <map>

std::map<char, int> build_char_counters(std::string word) {
    std::map<char, int> res;
    for (size_t i = 0; i != word.size(); ++i)
        ++res[word[i]];
    return res;
}

int main() {
    std::string word1, word2;
    int n;
    std::cin >> n;

    for (size_t i = 0; i != n; ++i) {
        std::cin >> word1 >> word2;
        if (build_char_counters(word1) == build_char_counters(word2)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
