#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

// Constants for array size
const int NUM_BINS = 10;


struct InventoryBin {

    string description;
    int num;

};

// Function prototypes
void selectBin(InventoryBin [], int);
void addParts(InventoryBin&, int);
void removeParts(InventoryBin&, int);

int main() {

    int choice;

    // Array of inventory bins
    InventoryBin bins[NUM_BINS] = {

        {"Valve", 10},
        {"Bearing", 5},
        {"Bushing", 15},
        {"Coupling", 21},
        {"Flange", 7},
        {"Gear", 5},
        {"Gear Housing", 5},
        {"Vacuum Gripper", 25},
        {"Cable", 18},
        {"Rod", 12}
    };

    do {

        for (int count = 0; count < 10; count++) {

            cout << "Bin #" << setw(3) << (count + 1);
            cout << ", Part: " << bins[count].description;
            cout << ", Quantity: " << bins[count].num << endl;
        }

        // Get the user's choice of bins
        cout << "\nEnter 0 to quit, or choose a bin Number: ";
        cin >> choice;

        //Valdiate the user's choice
        while (choice < 0 || choice > NUM_BINS) {

            cout << "\nEnter 0 to quit, or choose a bin number: ";
            cin >> choice;
        }

        if (choice != 0)
            selecteBins()
    } while (choice != 0);

    return 0;
}

void selectBin(InventoryBin bin[], int) {

    int numParts; // Number of parts
    char aorr; // Add or remove parts

    // Get the user's desired action (A or R)
    cout << "Add or Remove Parts (A or R)? ";
    cin >> aorr;

    // Validate the input
    while(toupper(aorr) != 'A' && toupper(aorr) != 'R') {

        cout << "Enter A or R: ";
        cin >> aorr;
    }

    // Process the selection. 'A' means Add, 'R' means Remove
    if (toupper(aorr) == 'A') {

        // Get the number of parts to add
        cout << "How many parts to add? ";
    }
}
void addParts(InventoryBin &bin, int numAdd) {

    // Validate the number of parts and add them if the number is valid
    if (numAdd < )
}
void removeParts(InventoryBin &bin, int numRem) {

    // Valid
}