#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    // To hold the Celsius temperature
    // To hold Fahrenheit temperature
    double celsius, farenheit;

    // To get the Celsius temperature
    cout << "Input temperature in celsius: ";
    cin >> celsius;

    // Convert Celsius to Fahrenheit
    farenheit = (celsius * 9)/5 + 32;

    //Display the Fahrenheit temperature
    cout << farenheit << " degrees Fahrenheit.\n";
    return 0;
}