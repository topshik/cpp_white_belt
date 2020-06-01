#include <iostream>
#include <exception>
#include <string>

std::string AskTimeServer() {
    throw std::domain_error("keeeeeeeeeeeeeeeeeek");
}

class TimeServer {
public:
    std::string GetCurrentTime() {
        try {
            last_fetched_time = AskTimeServer();
            return last_fetched_time;
        } catch (std::system_error& system_error_ex) {
            return last_fetched_time;
        } catch (std::exception& e) {
            throw e;
        }
    }
private:
    std::string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        std::cout << ts.GetCurrentTime() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception got: " << e.what() << std::endl;
    }
    return 0;
}
