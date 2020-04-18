#include <iostream>
#include <set>
#include <vector>
#include <map>

int main() {
    std::map<std::set<std::string>, int> buses;
    int q, max_bus_num, curr_stops_num;
    std::set<std::string> curr_stops;
    std::string curr_stop;
    std::cin >> q;
    max_bus_num = 1;
    for (size_t i = 0; i != q; ++i) {
        std::cin >> curr_stops_num;
        curr_stops.clear();
        for (size_t j = 0; j != curr_stops_num; ++j) {
            std::cin >> curr_stop;
            curr_stops.insert(curr_stop);
        }
        auto find = buses.find(curr_stops);
        if (find != buses.end()) {
            std::cout << "Already exists for " << (*find).second << std::endl;
        } else {
            buses[curr_stops] = max_bus_num;
            std::cout << "New bus "<< max_bus_num++ << std::endl;
        }
    }
    return 0;
}