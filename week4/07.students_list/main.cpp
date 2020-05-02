#include <iostream>
#include <vector>

struct Student {
    std::string first_name, last_name;
    int day, month, year;
};

int main() {
    int n, m;
    std::vector<Student> students;
    std::string first_name, last_name;
    int day, month, year;
    std::cin >> n;
    for (size_t i = 0; i != n; ++i) {
        std::cin >> first_name >> last_name >> day >> month >> year;
        students.push_back({first_name, last_name, day, month, year});
    }
    std::cin >> m;
    std::string request;
    int request_param;
    for (size_t i = 0; i != m; ++i) {
        std::cin >> request >> request_param;
        if (request == "name" && request_param <= students.size() && 1 <= request_param) {
            Student cur_student = students[request_param - 1];
            std::cout << cur_student.first_name << ' ' << cur_student.last_name << std::endl;
        } else if (request == "date" && request_param <= students.size() && 1 <= request_param) {
            Student cur_student = students[request_param - 1];
            std::cout << cur_student.day << '.' << cur_student.month << '.' << cur_student.year << std::endl;
        } else {
            std::cout << "bad request" << std::endl;
        }
    }
    return 0;
}
