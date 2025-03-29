#include <iostream>
using namespace std;

class shape {
private:
    float length;
    float width;

public:
    shape(float l = 0, float w = 0) : length(l), width(w) {}

    float Area() const {
        return length * width;
    }

    shape operator+(const shape& s) const {
        float totalArea = this->Area() + s.Area();
        return shape(totalArea, 1); // store area in length, dummy width
    }

    void displayArea() const {
        cout << "Area: " << Area() << endl;
    }
};

int main() {
    shape shape1(4, 5);   // Area = 20
    shape shape2(3, 6);   // Area = 18

    shape shape3 = shape1 + shape2;  // Total Area = 38

    cout << "Shape1 ";
    shape1.displayArea();

    cout << "Shape2 ";
    shape2.displayArea();

    cout << "Combined ";
    shape3.displayArea();

    return 0;
}
