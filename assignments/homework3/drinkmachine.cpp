#include <iostream>

using namespace std;

struct drinkMachine {

    string drinkName;
    double drinkCost;
    int numDrinksInStock;
};

int findDrink(string drink, drinkMachine *drinkMachines, int size);

int main() {

    drinkMachine drinkMachines[5] = {

        {"Coke", 0.5, 10},
        {"Pepsi", 1.0, 3},
        {"Fanta", 0.75, 15},
        {"Water", 0.5, 20},
        {"Tea", 0.25, 5}
    };

    bool runMachine = true;
    int size = sizeof(drinkMachines) / sizeof(drinkMachines[0]);
    double totalEarnings = 0;

    while (runMachine) {

        cout<<"Would you like to select a drink? Enter 1 for yes and 0 for no: ";
        cin>>runMachine;

        if(runMachine != false) {

            cout<<endl<<"DRINK STOCK";
            for (int i = 0; i < size; i++) {

                cout<<"Drink: "<<drinkMachines[i].drinkName<<endl;
                cout<<"Cost: $"<<drinkMachines[i].drinkCost<<endl;
                cout<<"Stock: "<<drinkMachines[i].numDrinksInStock<<endl;
                cout<<endl;
            }
        
            cout<<"What drink would you like?"<<endl;
            string selectedDrink;
            cin>>selectedDrink;

            int selectedDrinkIndex = findDrink(selectedDrink, drinkMachines, size);

            while(selectedDrinkIndex == -1) {

                cout<<"Invalid drink selection, try again: "<<endl;
                cin>>selectedDrink;
                selectedDrinkIndex = findDrink(selectedDrink, drinkMachines, size);
            }

            if (drinkMachines[selectedDrinkIndex].numDrinksInStock < 1) {

                cout<<"Drink sold out! Please select a different beverage"<<endl;
            }

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