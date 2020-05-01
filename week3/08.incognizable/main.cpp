#include <iostream>

class Incognizable {
public:
    Incognizable() = default;
    Incognizable(int a) {
        this->a = a;
    }
    Incognizable(int a, int b) {
        this->a = a;
        this->b = b;
    }
private:
    int a, b;
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}
