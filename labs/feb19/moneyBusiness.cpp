/*
Joshua Douglas
Assignment #2 - Monkey Business
Professor: Dr. Rory Lewis
Date: 2/23/25
Description:
(Monkey Business)
A local zoo wants to keep track of how many pounds of food each of its three monkeys cats each day during a typical week. Write a program that stores this information in a two-dimensional 3 x S array, where each row represents a different monkey, and each column represent a different day of the week. The program should first have the user input the data for each monkey. Then, it should create a report that includes the following information:
Write a program that stores this information in a two-dimensional 3 x 5 array, where each row represents a different
monkey, and each column represents a different day of the week. The program should first have the user input the data
for each monkey. Then, it should create a report that includes the following information:

- Average amount of food eaten per day by the whole family of monkeys
- The least amount of food eaten during the week by any on monkey
- The greatest amount of food eaten during the week by any one monkey
*/

#include <iostream>
#include <array>

using namespace std;

// Constants defining dimensions of 2d array
const int MONKEYS = 3;
const int DAYS = 5;

// Function prototypes
void getFoodEaten(double[][DAYS]);
void displayAverageDaily(double[][DAYS]);
void displayLeastEaten(double[][DAYS]);
void displayMostEaten(double[][DAYS]);

int main() {

    // 3x5 Array to store food consumption of monkeys throughout the week
    double monkeyData[MONKEYS][DAYS];

    // Collect amount of food eaten on each day for each monkey from user
    getFoodEaten(monkeyData);

    // Display the 
    displayAverageDaily(monkeyData);
    displayLeastEaten(monkeyData);
    displayMostEaten(monkeyData);

    return 0;
}

// Collect information on Monkey's food consumption
void getFoodEaten(double monkeyData[][DAYS]) {

    // For each monkey on each day, add the pounds eaten and divide by total days (5)
    for(int i = 0; i < MONKEYS; i++) {

        for (int j = 0; j < DAYS; j++) {

            // Collect Monkey Data
            double lbEaten;

            cout << "Input lb eaten for monkey " << i+1 << " on day " << j+1 << endl;
            cin >> lbEaten;

            // Input validation to ensure only positive values are put into 2d array
            while (lbEaten < 0) {

                cout << "ERROR: Pounds eaten cannot be a negative value, try again" << endl;
                cin >> lbEaten;
            }
            
            monkeyData[i][j] = lbEaten;
        }
    }
}

// Calculate the average amount of food eaten by all monkeys on each day
void displayAverageDaily(double monkeyData[][DAYS]) {

    // Iterate through each day
    for (int i = 0; i < DAYS; i++) {

        double average, sum = 0;

        // Find the total amount of food eaten by all monkeys on a certain day i
        for (int j = 0; j < MONKEYS; j++) {

            sum += monkeyData[j][i];
        }

        // Divide the total amount of food eaten on current day i by the number of monkeys to get average
        average = sum / MONKEYS;

        cout << "Average amount of food eaten by family of monkeys on day " << i+1 << ": " << average << endl;
    }

    
}

// Find and display the smallest amount of food eaten by any one monkey throughout the week
void displayLeastEaten(double monkeyData[][DAYS]) {

    // Set the least to start at the beginning of the 2d array
    double leastLbEaten = monkeyData[0][0];

    // Iterate through the array to check if there is a smaller value than the one at index [0][0]
    for (int i = 0; i < MONKEYS; i++) {

        for (int j = 0; j < DAYS; j++) {

            if (monkeyData[i][j] < leastLbEaten) {

                leastLbEaten = monkeyData[i][j];
            }
        }
    }

    cout << "The least amount of food eaten during the week by any one monkey: " << leastLbEaten << endl;
}

// Find and display the largest amount of food consumed by any one monkey on a given day
void displayMostEaten(double monkeyData[][DAYS]) {

    // Set most eaten to the first value in the 2d array
    double mostLbEaten = monkeyData[0][0];

    // Check if there is a smaller value than that at index [0][0] and continue until least found
    for (int i = 0; i < MONKEYS; i++) {

        for (int j = 0; j < DAYS; j++) {

            if (monkeyData[i][j] > mostLbEaten) {

                mostLbEaten = monkeyData[i][j];
            }
        }
    }

    cout << "The greatest amount of food eaten during the week by any one monkey: " << mostLbEaten << endl;
}