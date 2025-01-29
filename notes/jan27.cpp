#include <iostream>
#include <string>
using namespace std; // Helps debugger to avoid repeated names/function overlap issues

int main() {

    // Collecting input and output
    string s;

    cin >> s; // Take input using cin

    cout << s; // Print output

    // End line
    cout << "Programming is" << endl;
    cout << "fun!";

    cout << "Programming is\n fun!";

    // Using cin to collect user input
    int length, width, area;
    cout << "What is the length and width of the rectangle?\n";
    cin >> length;
    cin >> width;

    area = length * width;

    cout << "The area of the rectangle is: " << area << endl;

    // Variable assignment frome right to left
    // x = y = z = 5;
    // x = (y = (z = 5));


    return 0;
}