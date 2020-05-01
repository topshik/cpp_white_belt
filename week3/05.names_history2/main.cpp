#include <iostream>
#include <map>
#include <vector>

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

    std::string GetFullNameWithHistory(int year) {
        std::vector<std::string> first_name_hist = GetNameHistByHist(year, first_names);
        std::vector<std::string> last_name_hist = GetNameHistByHist(year, last_names);
        std::string res = "Incognito";
        if (first_name_hist.empty()) {
            if (last_name_hist.empty()) {
                return res;
            } else {
                res = *last_name_hist.rbegin();
                if (CheckHistNeeded(last_name_hist)) {
                    res += PrintHist(*last_name_hist.rbegin(), last_name_hist);
                }
                res += " with unknown first name";
            }
        } else {
            res = *first_name_hist.rbegin();
            if (CheckHistNeeded(first_name_hist)) {
                res += PrintHist(*first_name_hist.rbegin(), first_name_hist);
            }
            if (last_name_hist.empty()) {
                res += " with unknown last name";
            } else {
                res += ' ' + *last_name_hist.rbegin();
                if (CheckHistNeeded(last_name_hist)) {
                    res += PrintHist(*last_name_hist.rbegin(), last_name_hist);
                }
            }
        }
        return res;
    }

private:
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

    static std::string PrintHist(std::string last_name, const std::vector<std::string>& hist) {
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
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    std::cout << person.GetFullNameWithHistory(1990) << std::endl;

    person.ChangeFirstName(1966, "Pauline");
    std::cout << person.GetFullNameWithHistory(1966) << std::endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    std::cout << person.GetFullNameWithHistory(1967) << std::endl;

    return 0;
}

