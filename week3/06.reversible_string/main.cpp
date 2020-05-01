#include <iostream>

class ReversibleString {
public:
    ReversibleString() = default;
    explicit ReversibleString(const std::string& str) {
        content = str;
    }

    std::string ToString() const {
        return content;
    }

    void Reverse() {
        for (size_t i = 0; i != content.size() / 2; ++i) {
            std::swap(content[i], content[content.size() - i - 1]);
        }
    }

private:
    std::string content;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    std::cout << s.ToString() << std::endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    std::string tmp = s_ref.ToString();
    std::cout << tmp << std::endl;

    ReversibleString empty;
    std::cout << '"' << empty.ToString() << '"' << std::endl;

    return 0;
}