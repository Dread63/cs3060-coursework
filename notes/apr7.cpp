#include <iostream>

using namespace std;

class Rectangle {
protected:
    int width, height;
public:

    Rectangle(int w, int h) {
        width = w;
        height = h;
    }

    int area () {
        return width * height;
    }
};

class Square : public Rectangle { 
public:
    Square (int side) : Rectangle(side, side) {
    // Calls Rectangle constructor with width = side, height = side

    }

};

class Device {

    public:
        Device(int id) {

            cout << "Id = " << id << endl;
        }
};

class Printer : public Device {

    using Device::Device;
};

int main () {
    Square sq(5);
    cout << "Area of square:" << sq.area () << endl; return 0;

    Printer p1(100);

    return 0;
}
