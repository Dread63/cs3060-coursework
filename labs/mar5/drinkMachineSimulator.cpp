#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

// Constant for array
const int NUM_DRINKS = 5;

// Declaration of the Drink structure
struct Drink {

    string name;
    double price;
    int num;
};

// Function prototypes
int getChoice(Drink []);;
void transaction(Drink [], int, double &);

int main() {

    // Menu choice
    int choice;

    // Drink machine earnings
    double earnings = 0;

    // Array of drinks in the machine
    Drink machine[NUM_DRINKS] = {

        {"Cola", 0.75, 20},
        {"Root Beer", 0.75, 20},
        {"Lemon-Lime", 0.75, 20},
        {"Grade Soda", 0.80, 20},
        {"Cream Soda", 0.80, 20}
    };

    // Set the floating-point output formatting
    cout << fixed << showpoint << setprecision(2);

    // Display the menu and process the user's choice
    choice = getChoice(machine);
    while (choice != 5) {

        // Process the transaction
        transaction(machine, choice, earnings);

        // Get the next choice
        choice = getChoice(machine);
    }

    // Display the machine's total earnings
    cout << "Total earnings: $" << earnings << endl;
   return 0;
}

int getChoice(Drink m[]) {

    // The user's choice
    int choice;

    // Display a list of drinks preceded by a number
    // This will be the menu
    cout<<endl<<"DRINK STOCK";

        for (int i = 0; i < NUM_DRINKS; i++) {

            cout << (i+1) << ") " << m[i].name << "\t\t";
            cout << m[i].price << endl;
        }

    // Display the last menu item, which is to leave the drink machine
    cout << (NUM_DRINKS +1) << ") Leave the drink machine\n\n";

    // Get the user's choice
    cout << "Choose one: ";
    cin >> choice;

    // Validate the choice
    while (choice < 1 || choice > 6) {

        cout << "Bad choice. Choose one: ";
        cin >> choice;
    }

    // Return the choice, as a subscript into the array of drinks
    return choice - 1;
}

void transaction(Drink m[], int choice, double &earnings) {

    // The amount of money to be tendered
    double money;

    // If the selected drink is sold ouyt, display a message and get out of this function
    if (m[choice].num == 0) {

        cout << "Sorry, that selection is sold out.\n";
        return;
    }


    // Get some money from the customer
    cout << "Enter an amount of money: ";
    cin >> money;

    // Make sure the customer entered at least enough for the selected drink and no more than $1.00
    while(money < m[choice].price || money > 1.0) {

        cout << "Enter at least " << m[choice].price;
        cout << " and not more than 1 dollar.\n";
        cin >> money;
    }

    // Proccess the selection and give back any change that is due
    if (money >= m[choice].price) {

        // Dispense the drink
        cout << "\nThump, thump, thump, splat!\n" << "Enjoy your beverage!\n\n";

        // Calculate any due change
        cout << "Change calculated: " << m
    }
}