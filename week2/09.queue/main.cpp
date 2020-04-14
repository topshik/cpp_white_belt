#include <iostream>
#include <vector>

int worry_count(const std::vector<bool>& queue) {
    int cnt = 0;
    for (size_t i = 0; i != queue.size(); ++i)
        if (queue[i]) ++cnt;
    return cnt;
}

int main() {
    int q;
    std::vector<bool> queue;
    std::cin >> q;
    std::string curr_command;
    int curr_arg;
    for (size_t i = 0; i != q; ++i) {
        std::cin >> curr_command;
        if (curr_command == "WORRY_COUNT") {
            std::cout << worry_count(queue) << std::endl;
            continue;
        }
        std::cin >> curr_arg;
        if (curr_command == "COME") {
            if (curr_arg > 0) {
                std::vector<bool> newcomers(curr_arg, false);
                queue.insert(queue.end(), newcomers.begin(), newcomers.end());
            } else {
                queue.resize(queue.size() + curr_arg);
            }
        } else if (curr_command == "WORRY") {
            queue[curr_arg] = true;
        } else if (curr_command == "QUIET") {
            queue[curr_arg] = false;
        }
    }

    return 0;
}
