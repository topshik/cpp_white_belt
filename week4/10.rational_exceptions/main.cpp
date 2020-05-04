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
            throw std::invalid_argument("Can't initialize Rational with zero denominator");
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
        throw std::domain_error("Encountered division by zero");
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

int main() {
    try {
        Rational r(1, 0);
        std::cout << "Doesn't throw in case of zero denominator" << std::endl;
        return 1;
    } catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        std::cout << "Doesn't throw in case of division by zero" << std::endl;
        return 2;
    } catch (std::domain_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "OK" << std::endl;
    return 0;
}