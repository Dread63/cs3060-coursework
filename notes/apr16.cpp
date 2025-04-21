#include<iostream>

using namespace std;

class Shape_NonVirtual
{

    private:

    string shapeType;
    public:

        void print()
        {
            cout<<"NonVirt: I am a shape, not sure of what type"<<endl;
        }
};

class Shape_Virtual
{

    private:
        string shapeType;

    public:

        // The virtual keyword is used here
        // Compiler takes hidden _vPtr into the virtual table to find the function later 
        virtual void print()
        {
            cout<<"Virt: I am a shape, not sure of what type"<<endl;
        }
};

class Circle_NonVirtual : public Shape_NonVirtual
{
    public:
        
        void print()
        {
            cout<<"NonVirt: I am a circle"<<endl;
        }
};

class Circle_Virtual : public Shape_Virtual
{
    public:
        
        void print()
        {
            cout<<"Virt: I am a circle"<<endl;
        }
};

int main() {   

    Shape_Virtual s1;
    Shape_NonVirtual s2;

    cout<<"Size of object with vPtr is : "<<sizeof(s1)<<endl;
    cout<<"Size of object without vPtr is : "<<sizeof(s2)<<endl;
    
    Circle_Virtual c1;
    Circle_NonVirtual c2;

    cout << "Will the circles know their types?" << endl;
    cout << "Circle with the virtual function says:" << endl;
    c1.print();
    cout << "Circle without the virtual function says:" << endl;
    c2.print();

    cout<<"Now assign the circles to their base class types." << endl;
    //Shape_Virtual 
    s1 = c1;
    //Shape_NonVirtual 
    s2 = c2;

    cout << "NOW will the circles know their types"<<endl;
    s1.print();
    s2.print();

    cout << "Now assign the ircles to their base class pointer types." << endl;
    Shape_Virtual *sPtr1 = new Circle_Virtual();
    Shape_NonVirtual *sPtr2 = new Circle_NonVirtual();

    cout << "NOW Will the circles know their types?" << endl;
    sPtr1->print();
    sPtr2->print();

    cout << "Now assign the circles to their base class reference types" << endl;
    Shape_Virtual &sRef1 = c1;
    Shape_NonVirtual &sRef2 = c2;

    cout<<"NOW Will the circles know their types?" << endl;
    sRef1.print();
    sRef2.print();

    return 0;
}