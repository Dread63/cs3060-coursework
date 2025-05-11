#include<iostream>
using namespace std;

class Car {

    private:
        int year;
        string make;
        int speed;
    
    public:

        Car(int year, string make) : year(year), make(make), speed(0){}

        int getYear() {
            return year;

        }
        
        string getMake() {
            return make;
        }

        int getSpeed() {
            return speed;
        }

        void accelerate() {
            speed += 5;
        }

        void brake() {
            speed -= 5;
        }
};


int main() {

    Car c1(1999, "Ford");
    
    for (int i = 0; i < 5; i++) {

        c1.accelerate();
        cout << "Speed: " << c1.getSpeed() << endl;
    }
        
    for (int i = 0; i < 5; i++) {

        c1.brake();
        cout << "Speed: " << c1.getSpeed() << endl;
    }
    
    
}
