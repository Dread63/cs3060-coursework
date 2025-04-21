#include <iostream>

using namespace std;

// Shape Class
class Shape {
private:
    string shapeType;

public:
    Shape() {
        cout << "SHAPE: Inside the default constructor" << endl;
    }

    Shape(string s) : shapeType(s) {
        cout << "SHAPE: Inside the 1-argument constructor" << endl;
    }

    Shape(const Shape& rhs) {
        // Enables proper use of pass by value
        cout << "SHAPE: Inside the copy constructor" << endl;
        shapeType = rhs.shapeType;
    }

    ~Shape() {
        cout << "SHAPE: Inside the destructor" << endl;
    }

    Shape& operator=(const Shape& rhs) {
        cout << "SHAPE: Inside the assignment operator" << endl;
        // 1. check for self-assignment
        if (this != &rhs) {
            shapeType = rhs.shapeType;
        }
        // 5. Return *this
        return *this;
    }
};

// Circle Class
class Circle : public Shape {
private:
    float radius;

public:
    Circle() : radius(0.0) {
        cout << "CIRCLE: Inside the default constructor" << endl;
    }

    // Parameterized constructor because it has arguments inside of it
    Circle(string s, float r) : Shape(s), radius(r) {
        cout << "CIRCLE: Inside the 1-argument constructor" << endl;
    }

    Circle(const Circle& rhs) {
        cout << "CIRCLE: Inside the copy constructor" << endl;
        radius = rhs.radius;
    }

    ~Circle() {
        cout << "CIRCLE: Inside the destructor" << endl;
    }

    Circle& operator=(const Circle& rhs) {
        cout << "CIRCLE: Inside the assignment operator" << endl;
        // 1. check for self-assignment
        if (this != &rhs) {
            // Explicitly calling base class operator within the derived class
            Shape::operator=(rhs);
            radius = rhs.radius;
        }
        // 5. Return *this
        return *this;
    }
};

int main() {
    // Shape s("Some shape");
    cout << "Start of program" << endl;

    cout << "Instantiate object c1" << endl;
    Circle c1("Some shape", 3.5);

    cout << "Instantiate object c2" << endl;
    Circle c2("Some other shape", 10.2);

    cout << "Assign c1 = c2" << endl;
    c1 = c2;

    cout << "Instantiate object c3 (copy constructor)" << endl;
    Circle c3 = c1;

    cout << "End of program" << endl;
}
