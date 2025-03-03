#include<iostream>
#include<fstream>
#include<string>
#include <bits/stdc++.h> // This brings in EVERY include file

using namespace std;

struct Divison {

    char divName[SIZE];
    int quarter;
    double sales;
}

int main() {

    string input;
    fstream dataFile("cs3060_2019.txt", ios::in);
    fstream file("corp.dat", ios::out | ios::binary); // Reading a file in binary

    if (dataFile) {

        getline(dataFile, input, '$'); // Here the $ is used as the delimiter

        while(dataFile) {

            cout << input << endl;
            getline(dataFile, input, '$');
        }

        dataFile.close();
    }

    else {
        cout << "ERROR: Cannot open file.\n";
    }

    Divison east, west, north, south;
    int qtr;

    for (qtr = 1, q <=4; qtr++) {

        file.write(reinterpret_cast<* char>);
    }

    return 0;
}

class Monkey {

    public: // Access Specifier

    string monkeyName; // Data member

    void printname() // Member Functions()
        { cout << "Monkeyname is: " << monkeyName; }
};

int main2() {

    Monkey obj1;
    obj1.monkeuyName = "vervet"; // Accessing Data member
    obj1.printname(); // Accessing Member function
    return 0;
}

// CLASS EXAMPLE
class Rectange
{

    private:
        double width;
        double length;

    public:
        void setWidth(double);
        void setLength(double);
        double getWidth() const;
        double getLength() const;
        double getArea() const;
};

class C1 {
    int i = 0;

    public:
        void setvalue(int value) {i = value}; // Assigns value to i
        int getvalue() { return i; } // Returns stored value of i
}

int main3() {

    int i = 47;
    C1 o1;

    o1.setvalue(i); // Stores 47 in o1
    printf("value is %d\n", o1.getvalue());
    return 0;
}

