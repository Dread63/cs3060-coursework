#include<iostream>
#include<string>

using namespace std;

class Animal {

    public:

        virtual void speak() {
            cout<<"Animal sound"<<endl;
        }

};

class Dog : public Animal {
    
    public:
    
    void speak() override{

        cout<<"Woof!"<<endl;
    }
};

void playSound(Animal *a) {

    a->speak();
};

int main() {

    Animal a;
    Dog d;
    Animal* ptr = &d;

    playSound(&a); // Animal version
    playSound(ptr); // Dog version
            // Dynamic binding
}