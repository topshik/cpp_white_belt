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