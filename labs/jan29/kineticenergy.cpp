#include<iostream>
#include<cmath>
#include<string>
using namespace std;

// Function prototype
double calcKineticEnergy(double, double);

int main()
{
    // To hold mass, velocity, and kinetic energy
    double mass, velocity, kineticEnergy;

    // Prompt user to enter mass
    cout << "Input mass of the object in kilograms: ";
    cin >> mass;

    // Propmt user to enter velocity
    cout << "Input velocity of the object in meters per second: ";
    cin >> velocity;

    // Calculate kinetic energy using mass and velocity
    kineticEnergy = calcKineticEnergy(mass, velocity);

    // Output kinetiic energy value
    cout << "The kinetic energy of the object is: " << kineticEnergy << " Joules.\n";
    return 0;
}

double calcKineticEnergy(double mass, double velocity)
{

    return (mass * pow(velocity, 2)) * 0.5;
}