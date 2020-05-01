#include <iostream>
#include <map>

class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const std::string& last_name) {
        last_names[year] = last_name;
    }
    std::string GetFullName(int year) {
        std::string first_name = GetNameByHist(year, first_names);
        std::string last_name = GetNameByHist(year, last_names);
        if (first_name.empty()) {
            if (last_name.empty()) {
                return "Incognito";
            } else {
                return last_name + " with unknown first name";
            }
        } else {
            if (last_name.empty()) {
                return first_name + " with unknown last name";
            } else {
                return first_name + ' ' + last_name;
            }
        }
    }

private:
    std::map<int, std::string> first_names;
    std::map<int, std::string> last_names;

    std::string GetNameByHist(int year, const std::map<int, std::string>& hist) {
        if (year < (*hist.begin()).first) return "";

        std::string res_name = (*hist.begin()).second;
        for (const auto& [hist_year, hist_name] : hist) {
            if (hist_year <= year) {
                res_name =  hist_name;
            }
        }
        return res_name;
    }
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        std::cout << person.GetFullName(year) << std::endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullName(year) << std::endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullName(year) << std::endl;
    }

    return 0;
}
