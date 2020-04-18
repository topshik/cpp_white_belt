#include <iostream>
#include <map>
#include <vector>

int main() {
    std::map<std::vector<std::string>, int> buses;
    int q, max_bus_num, curr_stops_num;
    std::vector<std::string> curr_stops;
    std::cin >> q;
    max_bus_num = 1;
    for (size_t i = 0; i != q; ++i) {
        std::cin >> curr_stops_num;
        curr_stops.resize(curr_stops_num);
        for (size_t j = 0; j != curr_stops_num; ++j) {
            std::cin >> curr_stops[j];
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
