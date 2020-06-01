#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <iomanip>

class Date {
public:
    Date ()= default;
    Date (const std::string& date) {
        std::stringstream stream(date);
        if (std::isdigit(stream.peek()) || stream.peek() == '-' || stream.peek() == '+') {
            stream >> year;
            if (stream.peek() == '-') {
                stream.ignore(1);
                if (stream.peek() == '-') {
                    stream.ignore(1);
                    if (!std::isdigit(stream.peek())) {
                        throw std::invalid_argument("Wrong date format: " + date);
                    }
                    stream >> month;
                    month *= -1;
                } else {
                    stream >> month;
                }

                if (stream.peek() == '-') {
                    stream.ignore(1);
                    if (stream.peek() == '-') {
                        stream.ignore(1);
                        if (!std::isdigit(stream.peek())) {
                            throw std::invalid_argument("Wrong date format: " + date);
                        }
                        stream >> day;
                        day *= -1;
                    } else {
                        if (std::isdigit(stream.peek()) || stream.peek() == '+') {
                            stream >> day;
                        } else {
                            throw std::invalid_argument("Wrong date format: " + date);
                        }
                    }
                } else {
                    throw std::invalid_argument("Wrong date format: " + date);
                }

                if (stream.peek() != EOF) {
                    throw std::invalid_argument("Wrong date format: " + date);;
                }

                if (month < 1 || 12 < month) {
                    throw std::domain_error("Month value is invalid: " + std::to_string(month));
                }
                if (day < 1 || 31 < day) {
                    throw std::domain_error("Day value is invalid: " + std::to_string(day));
                }
                return;
            }
        }
        throw std::invalid_argument("Wrong date format: " + date);
    }
    int GetYear() const {
        return this->year;
    }
    int GetMonth() const {
        return this->month;
    }
    int GetDay() const {
        return this->day;
    }
private:
    int year, month, day;
};

bool operator<(Date date1, Date date2) {
    if (date1.GetYear() < date2.GetYear()) {
        return true;
    } else if (date1.GetYear() > date2.GetYear()) {
        return false;
    } else {
        if (date1.GetMonth() < date2.GetMonth()) {
            return true;
        } else if (date1.GetMonth() > date2.GetMonth()) {
            return false;
        } else {
            return date1.GetYear() < date2.GetYear();
        }
    }
}

std::ostream& operator<<(std::ostream& stream, const Date& date) {
    stream << std::setfill('0') << std::setw(4) << date.GetYear() << '-'
           << std::setw(2) << date.GetMonth() << '-' << std::setw(2)
           << date.GetDay();
    return stream;
}

std::istream& operator>>(std::istream& stream, Date& date) {
    std::string data;
    stream >> data;
    date = Date(data);
    return stream;
}

class DataBase {
public:
    DataBase() = default;

    void Add(const Date& date, const std::string& event) {
        database[date].insert(event);
    }

    void Del(const Date& date, const std::string& event) {
        auto events_it = database.find(date);
        if (events_it != database.end()) {
            if ((*events_it).second.find(event) != (*events_it).second.end()) {
                (*events_it).second.erase(event);
                std::cout << "Deleted successfully" << std::endl;
            } else {
                std::cout << "Event not found" << std::endl;
            }
        } else {
            std::cout << "Event not found" << std::endl;
        }
    }

    void Del(const Date& date) {
        int events_num = database[date].size();
        database.erase(date);
        std::cout << "Deleted " << events_num << " events" << std::endl;
    }

    void Find(const Date& date) const {
        auto events_it = database.find(date);
        if (events_it != database.end()) {
            for (const auto& event : (*events_it).second) {
                std::cout << event << std::endl;
            }
        }
    }

    void Print() const {
        for (const auto& [date, events] : database) {
            for (const auto& event : events) {
                std::cout << date << ' ' << event << std::endl;
            }
        }
    }
private:
    std::map<Date, std::set<std::string>> database;
};

int main() {
    DataBase db = DataBase();
    std::string line;
    while (getline(std::cin, line)) {
        if (line.empty()) {
            continue;
        }
        std::stringstream stream(line);
        if (stream) {
            std::string command, event;
            Date date;
            stream >> command;
            if (command == "Add") {
                try {
                    stream >> date;
                    stream >> event;
                    db.Add(date, event);
                } catch (std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
            } else if (command == "Del") {
                try {
                    stream >> date;
                    stream >> event;
                    if (!event.empty()) {
                        db.Del(date, event);
                    } else {
                        db.Del(date);
                    }
                } catch (std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
            } else if (command == "Find") {
                try {
                    stream >> date;
                    db.Find(date);
                } catch (std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
            } else if (command == "Print") {
                db.Print();
            } else {
                std::cout << "Unknown command: " << command << std::endl;
            }
        }
    }
    return 0;
}
