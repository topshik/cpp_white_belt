#include <iostream>
#include <map>
#include <vector>

class Person {
public:
    Person(const std::string& first_name, const std::string& last_name, int birth) {
        birth_year = birth;
        first_names[birth] = first_name;
        last_names[birth] = last_name;
    }

    void ChangeFirstName(int year, const std::string& first_name) {
        if (year < birth_year) return;
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const std::string& last_name) {
        if (year < birth_year) return;
        last_names[year] = last_name;
    }

    std::string GetFullName(int year) const {
        if (year < birth_year) return "No person";
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

    std::string GetFullNameWithHistory(int year) const {
        if (year < birth_year) return "No person";
        std::vector<std::string> first_name_hist = GetNameHistByHist(year, first_names);
        std::vector<std::string> last_name_hist = GetNameHistByHist(year, last_names);
        std::string res = "Incognito";
        if (first_name_hist.empty()) {
            if (last_name_hist.empty()) {
                return res;
            } else {
                res = *last_name_hist.rbegin();
                if (CheckHistNeeded(last_name_hist)) {
                    res += GetHistForPrint(*last_name_hist.rbegin(), last_name_hist);
                }
                res += " with unknown first name";
            }
        } else {
            res = *first_name_hist.rbegin();
            if (CheckHistNeeded(first_name_hist)) {
                res += GetHistForPrint(*first_name_hist.rbegin(), first_name_hist);
            }
            if (last_name_hist.empty()) {
                res += " with unknown last name";
            } else {
                res += ' ' + *last_name_hist.rbegin();
                if (CheckHistNeeded(last_name_hist)) {
                    res += GetHistForPrint(*last_name_hist.rbegin(), last_name_hist);
                }
            }
        }
        return res;
    }

private:
    int birth_year;
    std::map<int, std::string> first_names;
    std::map<int, std::string> last_names;

    static bool CheckHistNeeded(const std::vector<std::string>& hist) {
        const auto name = hist.rbegin();
        if (hist.size() <= 1) {
            return false;
        }
        for (auto it = ++hist.rbegin(); it != hist.rend(); ++it) {
            if (*it != *name) {
                return true;
            }
        }
        return false;
    }

    static std::string GetNameByHist(int year, const std::map<int, std::string>& hist) {
        if (year < (*hist.begin()).first) return "";

        std::string res_name = (*hist.begin()).second;
        for (const auto& [hist_year, hist_name] : hist) {
            if (hist_year <= year) {
                res_name =  hist_name;
            }
        }
        return res_name;
    }

    static std::vector<std::string> GetNameHistByHist(int year, const std::map<int, std::string>& hist) {
        std::vector<std::string> res;
        for (const auto& [hist_year, hist_name] : hist) {
            if (hist_year <= year) {
                res.push_back(hist_name);
            }
        }
        return res;
    }

    static std::string GetHistForPrint(std::string last_name, const std::vector<std::string>& hist) {
        std::string res = " (";
        for (auto it = ++hist.rbegin(); it != --hist.rend(); ++it) {
            if (last_name != *it) {
                res += *it + ", ";
                last_name = *it;
            }
        }
        res += *--hist.rend() + ')';
        return res;
    }
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    return 0;
}

