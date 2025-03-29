#include <iostream>

class Number {
private:
    int value;

public:
    Number(int v) : value(v) {}

    // Prefix --
    Number& operator--() {
        value *= 4;
        return *this;
    }

    // Postfix --
    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    void display() const {
        std::cout << value << std::endl;
    }
};

int main() {
    Number num(8);

    std::cout << "Original: ";
    num.display();

    --num;
    std::cout << "After prefix -- (multiplied by 4): ";
    num.display();

    num--;
    std::cout << "After postfix -- (divided by 4): ";
    num.display();

    return 0;
}
