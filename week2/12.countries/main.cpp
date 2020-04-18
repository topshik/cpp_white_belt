#include <iostream>
#include <map>

int main() {
    std::map<std::string, std::string> countries;
    std::string command, old_country, curr_country, capital;
    bool old_existed, curr_existed;
    int q;
    std::cin >> q;
    for (size_t i = 0; i != q; ++i) {
        std::cin >> command;
        if (command == "CHANGE_CAPITAL") {
            std::cin >> curr_country >> capital;
            old_existed = countries.find(curr_country) != countries.end();
            if (!old_existed) {
                countries[curr_country] = capital;
                std::cout << "Introduce new country " << curr_country << " with capital " << capital << std::endl;
            } else {
                if (countries[curr_country] == capital) {
                    std::cout << "Country " << curr_country << " hasn't changed its capital" << std::endl;
                } else {
                    std::cout << "Country " << curr_country << " has changed its capital from "
                              << countries[curr_country] << " to " << capital << std::endl;
                    countries[curr_country] = capital;
                }
            }
        } else if (command == "RENAME") {
            std::cin >> old_country >> curr_country;
            old_existed = countries.find(old_country) != countries.end();
            curr_existed = countries.find(curr_country) != countries.end();
            if (!old_existed || curr_existed) {
                std::cout << "Incorrect rename, skip" << std::endl;
            } else {
                countries[curr_country] = countries[old_country];
                countries.erase(old_country);
                std::cout << "Country " << old_country << " with capital " << countries[curr_country]
                          << " has been renamed to " << curr_country << std::endl;
            }
        } else if (command == "ABOUT") {
            std::cin >> curr_country;
            curr_existed = countries.find(curr_country) != countries.end();
            if (!curr_existed) {
                std::cout << "Country " << curr_country << " doesn't exist" << std::endl;
            } else {
                std::cout << "Country " << curr_country << " has capital " << countries[curr_country] << std::endl;
            }
        } else if (command == "DUMP") {
            if (countries.empty()) {
                std::cout << "There are no countries in the world" << std::endl;
            } else {
                for (auto [country, capital] : countries) {
                    std::cout << country << '/' << capital << ' ';
                }
                std::cout << std::endl;
            }
        }
    }
    return 0;
}
