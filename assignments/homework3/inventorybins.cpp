#include <iostream>
#include <string>

using namespace std;

#define MAX_STRING 80

// Structure to simulate a storage bin
struct bin {

    string binDescription;
    int numParts;

};

// Function prototypes
void addParts(bin *inventoryBins, int selectedBinIndex);
void removeParts(bin *inventoryBins, int selectedBinIndex);
int getBinIndex(bin *inventoryBins, string selectedBin, int size);

int main() {

    bin inventoryBins[10] = {

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

    bool displayingBins = true;

    // Run as long as the user still wants to edit bins
    while(displayingBins)  {

        // Display each bin, whats stored in each, and the stock
        cout<<"-----BIN DATA-----";

        int size = sizeof(inventoryBins) / sizeof(inventoryBins[0]);

        for (int i = 0; i < size; i++) {

            cout<<"Bin: "<<inventoryBins[i].binDescription<<endl<<"Inventory: "<<inventoryBins[i].numParts<<endl;
        }

        // Collect user input
        cout<<"Would you like to select a bin? Enter 1 for yes and 0 for no: ";
        cin>>displayingBins;

        // As long as the user wants to keep editing bins, let them select bin and remove/add members
        if(displayingBins != false) {

            cout<<"Please enter the name of the bin you would like to access: ";
            string selectedBin;
            cin.ignore();
            getline(cin, selectedBin);
            int selectedBinIndex = getBinIndex(inventoryBins, selectedBin, size);

            cout<<"Please input 1 or 2 for:"<<endl;
            cout<<"1. Add parts to selected bin"<<endl;
            cout<<"2. Remove parts from selected bin"<<endl;

            int selectedBinAction;
            cin>>selectedBinAction;

            // The user would like to add parts to the bin
            if (selectedBinAction == 1) {

                addParts(inventoryBins, selectedBinIndex);
            }

            // The user would like to remove parts from the bin
            else if (selectedBinAction == 2) {

                removeParts(inventoryBins, selectedBinIndex);
            }

            // Input validation for bin action selection
            else {

                cout<<"Invalid action selected, please restart";
            }
        }
    }
}

// Take the bin and the index indicating which bin is selected to add a given value to the bins stock
void addParts(bin *inventoryBins, int selectedBinIndex) {

    int partsToAdd;
    cout<<"How many parts would you like to add to the "<< inventoryBins[selectedBinIndex].binDescription<<" bin: ";
    cin>>partsToAdd;

    // Input validation to ensure parts don't go negative or over 30
    while(inventoryBins[selectedBinIndex].numParts+partsToAdd > 30 || partsToAdd < 0) {

        cout<<"Invalid input, please enter a non-negative value which will keep the number of parts under 30: ";
        cin>>partsToAdd;
    }

    inventoryBins[selectedBinIndex].numParts+=partsToAdd;
}

// Take the bin and the index indicating which bin is selected to remove a given value from bins stock
void removeParts(bin *inventoryBins, int selectedBinIndex) {

    int partsToRemove;
    cout<<"How many parts would you like to remove from the "<< inventoryBins[selectedBinIndex].binDescription<<" bin: ";
    cin>>partsToRemove;

    // Input validation to ensure parts don't go negative or over 30
    while(inventoryBins[selectedBinIndex].numParts-partsToRemove < 0) {

        cout<<"Invalid input, please enter a non-negative value which will keep the number of parts under 30: ";
        cin>>partsToRemove;
    }

    inventoryBins[selectedBinIndex].numParts-=partsToRemove;
}

// Locate the index of the selected bin
int getBinIndex(bin *inventoryBins, string selectedBin, int size) {

    for (int i = 0; i < size; i++) {

        if (selectedBin == inventoryBins[i].binDescription) {

            return i;
        }
    }

    return -1; 
}