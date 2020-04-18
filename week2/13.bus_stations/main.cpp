#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

std::vector<std::string> buses_for_stop(std::map<std::string, std::vector<std::string>>& buses, const std::vector<std::string>& buses_order, const std::string& stop) {
    std::vector<std::string> res;
    for (const auto& bus : buses_order) {
        if (std::find(buses[bus].begin(), buses[bus].end(), stop) != buses[bus].end()) {
            res.push_back(bus);
        }
    }
    return res;
}

int main() {
    int stop_count, q;
    std::map<std::string, std::vector<std::string>> buses;
    std::vector<std::string> buses_order;
    std::string bus_name, command, stop;
    std::vector<std::string> buses_for_stop_vec;
    std::cin >> q;
    for (size_t i = 0; i != q; ++i) {
        std::cin >> command;
        if (command == "NEW_BUS") {
            std::cin >> bus_name >> stop_count;
            buses[bus_name].resize(stop_count);
            buses_order.push_back(bus_name);
            for (size_t j = 0; j != stop_count; ++j) {
                std::cin >> buses[bus_name][j];
            }
        } else if (command == "BUSES_FOR_STOP") {
            std::cin >> stop;
            buses_for_stop_vec = buses_for_stop(buses, buses_order, stop);
            if (buses_for_stop_vec.empty()) {
                std::cout << "No stop" << std::endl;
            } else {
                for (const auto& bus : buses_order) {
                    if (std::find(buses_for_stop_vec.begin(), buses_for_stop_vec.end(), bus) != buses_for_stop_vec.end()) {
                        std::cout << bus << ' ';
                    }
                }
                std::cout << std::endl;
            }
        } else if (command == "STOPS_FOR_BUS") {
            std::cin >> bus_name;
            if (buses.find(bus_name) == buses.end()) {
                std::cout << "No bus" << std::endl;
                continue;
            }
            for (const auto& stop : buses[bus_name]) {
                std::cout << "Stop " << stop << ": ";
                bool unique = true;
                for (auto bus : buses_for_stop(buses, buses_order, stop)) {
                    if (bus != bus_name) {
                        std::cout << bus << ' ';
                        unique = false;
                    }
                }
                if (unique) std::cout << "no interchange";
                std::cout << std::endl;
            }
        } else if (command == "ALL_BUSES") {
            if (buses.empty()) {
                std::cout << "No buses" << std::endl;
                continue;
            }
            for (const auto& [bus, stops] : buses) {
                if (!stops.empty()) {
                    std::cout << "Bus " << bus << ": ";
                    for (const auto &stop : stops) {
                        std::cout << stop << ' ';
                    }
                    std::cout << std::endl;
                }
            }
        }
    }
    return 0;
}
