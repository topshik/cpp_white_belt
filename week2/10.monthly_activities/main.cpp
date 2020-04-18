#include <iostream>
#include <vector>

int main() {
    int q, day_for_add, day_for_dump, curr_month, prev_days_num, curr_days_num;
    std::vector<std::vector<std::string>> todos(31);
    std::vector<int> months_days_num = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string curr_command, activity_to_add;

    std::cin >> q;
    curr_month = 0;
    curr_days_num = 31;
    for (size_t i = 0; i != q; ++i) {
        std::cin >> curr_command;
        if (curr_command == "ADD") {
            std::cin >> day_for_add >> activity_to_add;
            todos[day_for_add - 1].push_back(activity_to_add);
        } else if (curr_command == "DUMP") {
            std::cin >> day_for_dump;
            std::cout << todos[day_for_dump - 1].size() << ' ';
            for (auto activity : todos[day_for_dump - 1]) {
                std::cout << activity << ' ';
            }
            std::cout << std::endl;
        } else if (curr_command == "NEXT") {
            if (curr_month == 11) {
                curr_month = 0;
                prev_days_num = 31;
            } else {
                ++curr_month;
                prev_days_num = curr_days_num;
                curr_days_num = months_days_num[curr_month];
            }

            if (curr_days_num > prev_days_num) {
                todos.resize(curr_days_num);
            } else {
                auto last_day_end = std::end(todos[curr_days_num - 1]);
                for (size_t i = curr_days_num; i != prev_days_num; ++i) {
                    last_day_end = std::end(todos[curr_days_num - 1]);
                    todos[curr_days_num - 1].insert(last_day_end, std::begin(todos[i]), std::end(todos[i]));
                }
                todos.resize(curr_days_num);
            }
        }
    }
    return 0;
}
