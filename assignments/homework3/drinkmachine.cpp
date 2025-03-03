#include <iostream>

using namespace std;

// Structure to store drink machine
struct drinkMachine {

    string drinkName;
    double drinkCost;
    int numDrinksInStock;
};

// Function prototypes
int findDrink(string drink, drinkMachine *drinkMachines, int size);

int main() {

    drinkMachine drinkMachines[5] = {

        {"Cola", 0.75, 20},
        {"Root Beer", 0.75, 20},
        {"Lemon-Lime", 0.75, 20},
        {"Grade Soda", 0.80, 20},
        {"Cream Soda", 0.80, 20}
    };

    bool runMachine = true;
    int size = sizeof(drinkMachines) / sizeof(drinkMachines[0]);
    double totalEarnings = 0;

    // While the user wants to continue buying drinks
    while (runMachine) {

        cout<<"Would you like to select a drink? Enter 1 for yes and 0 for no: ";
        cin>>runMachine;

        if(runMachine != false) {

            // Display drinks, stock, and price
            cout<<endl<<"DRINK STOCK";
            for (int i = 0; i < size; i++) {

                cout<<"Drink: "<<drinkMachines[i].drinkName<<endl;
                cout<<"Cost: $"<<drinkMachines[i].drinkCost<<endl;
                cout<<"Stock: "<<drinkMachines[i].numDrinksInStock<<endl;
                cout<<endl;
            }
            
            // Collect user input
            cout<<"What drink would you like?"<<endl;
            string selectedDrink;
            cin.ignore();
            getline(cin, selectedDrink);

            int selectedDrinkIndex = findDrink(selectedDrink, drinkMachines, size);

            // Make sure the drink selection was valid
            while(selectedDrinkIndex == -1) {

                cout<<"Invalid drink selection, try again: "<<endl;
                cin.ignore();
                getline(cin, selectedDrink);
                selectedDrinkIndex = findDrink(selectedDrink, drinkMachines, size);
            }

            // Check if drinks are sold out
            if (drinkMachines[selectedDrinkIndex].numDrinksInStock < 1) {

                cout<<"Drink sold out! Please select a different beverage"<<endl;
            }

            // If a valid drink was chosen and the drink isn't sold out, give the change and update stock
            else {

                double payment = 0.0;

                cout<<"Input amount of money into machine: ";
                cin>>payment;

                while(payment < 0 || payment > 1) {

                    cout<<"Invalid dollar entry: Please input a non-negative value less than one: ";
                    cin>>payment;
                }

                totalEarnings+=payment;
                cout<<"You change is: "<<(payment - drinkMachines[selectedDrinkIndex].drinkCost)<<endl;
                drinkMachines[selectedDrinkIndex].numDrinksInStock -= 1;
            }
        }
    }
    
    // When user is done using the drink machine, display the total earnings
    cout<<"Total earnings today: ";
    cout<<totalEarnings<<endl;
}

// Return the index of the selected drink or return -1 if the drink isn't found
int findDrink(string drink, drinkMachine *drinkMachines, int size) {

    for (int i = 0; i < size; i++) {

        if (drink == drinkMachines[i].drinkName) {

            return i;
        }
    }

    return -1;
}