#include <algorithm>
#include <iostream>
#include <vector>

class SortedStrings {
public:
    void AddString(const std::string& s) {
        strings.push_back(s);
        std::sort(strings.begin(), strings.end());
    }
    std::vector<std::string> GetSortedStrings() {
        std::vector<std::string> res(strings.begin(), strings.end());
        return res;
    }
private:
    std::vector<std::string> strings;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const std::string& s : strings.GetSortedStrings()) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}

