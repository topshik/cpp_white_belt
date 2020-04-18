#include <iostream>
#include <set>
#include <map>

int main() {
    std::map<std::string, std::set<std::string>> synonyms;
    std::string command, word1, word2;
    int q;
    std::cin >> q;
    for (size_t i = 0; i != q; ++i) {
        std::cin >> command;
        if (command == "ADD") {
            std::cin >> word1 >> word2;
            synonyms[word1].insert(word2);
            synonyms[word2].insert(word1);
        } else if (command == "COUNT") {
            std::cin >> word1;
            std::cout << synonyms[word1].size() << std::endl;
        } else if (command == "CHECK") {
            std::cin >> word1 >> word2;
            if (synonyms[word1].find(word2) != synonyms[word1].end()) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
    return 0;
}
