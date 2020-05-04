#include <iostream>
#include <numeric>
#include <set>

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Invalid argument");
        }
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (numerator * denominator >= 0) {
            p = (int)abs(numerator);
        } else {
            p = -(int)abs(numerator);
        }
        q = (int)abs(denominator);
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    int p, q;
};

bool operator==(const Rational& a, const Rational& b) {
    return a.Numerator() == b.Numerator() && a.Denominator() == b.Denominator();
}

bool operator<(const Rational& a, const Rational& b) {
    return a.Numerator() * b.Denominator() < b.Numerator() * a.Denominator();
}

Rational operator+(Rational a, Rational b) {
    return {a.Numerator() * b.Denominator() + b.Numerator() * a.Denominator(), a.Denominator() * b.Denominator()};
}

Rational operator-(Rational a, Rational b) {
    return {a.Numerator() * b.Denominator() - b.Numerator() * a.Denominator(), a.Denominator() * b.Denominator()};
}

Rational operator*(Rational a, Rational b) {
    return {a.Numerator() * b.Numerator(), a.Denominator() * b.Denominator()};
}

Rational operator/(Rational a, Rational b) {
    if (b.Numerator() == 0) {
        throw std::domain_error("Division by zero");
    }
    return {a.Numerator() * b.Denominator(), a.Denominator() * b.Numerator()};
}

std::ostream& operator<<(std::ostream& stream, const Rational& a) {
    stream << a.Numerator() << '/' << a.Denominator();
    return stream;
}

std::istream& operator>>(std::istream& stream, Rational& a) {
    if (stream) {
        int p, q;
        stream >> p;
        stream.ignore(1);
        if (stream) {
            stream >> q;
            a = Rational(p, q);
        } else {
            return stream;
        }
    }
    return stream;
}

Rational ApplyOperation(const Rational& a, const Rational& b, const char operation) {
    if (operation == '+') {
        return a + b;
    } else if (operation == '*') {
        return a * b;
    } else if (operation == '-') {
        return a - b;
    } else {
        return a / b;
    }
}

int main() {
    Rational a, b;
    char operation;
    try {
        std::cin >> a >> operation >> b;
    } catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    try {
        std::cout << ApplyOperation(a, b, operation);
    } catch (std::domain_error& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}