#include<iostream>
#include<string>

using namespace std;

// Template for the minimum function
template <class T> T minimum(T number1, T number2) {

    return (number1 < number2) ? number1 : number2;
}

// Template for the maximum function
template <class T> T maximum(T number1, T number2) {

    return (number1 > number2) ? number1 : number2;
}


// The main function
int main() {

    int num1 = 5;
    int num2 = 3;

    cout << "The minimum of 5, 3 is: ";
    cout << minimum(3, 5) << endl;

    cout << "The maximum of 5, 3 is: ";
    cout << maximum(3, 5) << endl;

    double num3 = 8.5;
    double num4 = 15.2;

    cout << "The minimum of 8.5, 15.2 is: ";
    cout << minimum(num3, num4) << endl;

    cout << "The maximum of 8.5, 15.2 is: ";
    cout << maximum(num3, num4) << endl;


    string s1 = "Hello";
    string s2 = "Goodbye";

    cout << "The minimum of 'Hello' and 'Goodbye' is: ";
    cout << minimum(s1, s2) << endl;

    cout << "The maximum of 'Hello' and 'Goodbye' is: ";
    cout << maximum(s1, s2) << endl;

    return 0;
}