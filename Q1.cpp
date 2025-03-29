#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce() {
        int divisor = gcd(abs(numerator), abs(denominator));
        numerator /= divisor;
        denominator /= divisor;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator,
                        denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Division by zero.");
        }
        return Fraction(numerator * other.denominator,
                        denominator * other.numerator);
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator<=(const Fraction& other) const {
        return *this < other || *this == other;
    }

    bool operator>(const Fraction& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.denominator == 1)
            os << f.numerator;
        else
            os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        int num, den;
        char slash;
        is >> num >> slash >> den;
        if (slash != '/' || den == 0) {
            is.setstate(ios::failbit);
        } else {
            f = Fraction(num, den);
        }
        return is;
    }
};

int main() {
    Fraction f1(2, 3), f2(3, 6);
    cout << (f1 + f2) << endl;
    return 0;
}
