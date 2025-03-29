#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool negative;

    void trim() {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
        if (digits.size() == 1 && digits[0] == 0)
            negative = false;
    }

    static bool absLess(const BigInteger& a, const BigInteger& b) {
        if (a.digits.size() != b.digits.size())
            return a.digits.size() < b.digits.size();
        for (int i = a.digits.size() - 1; i >= 0; --i)
            if (a.digits[i] != b.digits[i])
                return a.digits[i] < b.digits[i];
        return false;
    }

public:
    BigInteger() : digits(1, 0), negative(false) {}

    BigInteger(string s) {
        negative = false;
        if (s[0] == '-') {
            negative = true;
            s = s.substr(1);
        }
        reverse(s.begin(), s.end());
        for (char c : s)
            digits.push_back(c - '0');
        trim();
    }

    BigInteger operator+(const BigInteger& other) const {
        if (negative == other.negative) {
            BigInteger result;
            result.negative = negative;
            result.digits.clear();
            int carry = 0;
            for (size_t i = 0; i < max(digits.size(), other.digits.size()) || carry; ++i) {
                int sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < other.digits.size()) sum += other.digits[i];
                result.digits.push_back(sum % 10);
                carry = sum / 10;
            }
            result.trim();
            return result;
        } else {
            if (negative)
                return other - (-(*this));
            else
                return *this - (-other);
        }
    }

    BigInteger operator-(const BigInteger& other) const {
        if (!negative && other.negative)
            return *this + (-other);
        if (negative && !other.negative)
            return -((-*this) + other);

        if (absLess(*this, other))
            return -(other - *this);

        BigInteger result;
        result.digits.clear();
        int carry = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            int diff = digits[i] - carry;
            if (i < other.digits.size()) diff -= other.digits[i];
            if (diff < 0) {
                diff += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            result.digits.push_back(diff);
        }
        result.negative = negative;
        result.trim();
        return result;
    }

    BigInteger operator-() const {
        BigInteger result = *this;
        if (!(digits.size() == 1 && digits[0] == 0))
            result.negative = !negative;
        return result;
    }

    bool operator==(const BigInteger& other) const {
        return digits == other.digits && negative == other.negative;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (negative != other.negative)
            return negative;
        if (negative)
            return absLess(other, *this);
        return absLess(*this, other);
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    friend istream& operator>>(istream& is, BigInteger& num) {
        string s;
        is >> s;
        num = BigInteger(s);
        return is;
    }

    friend ostream& operator<<(ostream& os, const BigInteger& num) {
        if (num.negative) os << "-";
        for (int i = num.digits.size() - 1; i >= 0; --i)
            os << num.digits[i];
        return os;
    }
};

int main() {
    BigInteger a, b;
    cin >> a >> b;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    return 0;
}
