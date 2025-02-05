/*
Write a program that lets a maker of chips and salsa keep track of sales for five different
types of salsas: mild, medium, sweet, hot, and zesty. The program should use two parallel 5-element
arrays: an array of strings that holds the five salsa names, and an array of integers that holds
the number of jars sold during the past month for each salsa type. The salsa names should be stored
using an initialization list at the time name array is created. The program should prompt the user to enter
the number of jars sold for each type. Once this sales data has been entered, the program should
produce a report that displays sales for each salsa type, total sales, and the names of the highest
selling and lowest selling products.

Input validation: Do not accept negative values for number of jars sold
*/

//HOMEWORK: ADD AVERAGE AMOUNT OF JARS SOLD

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

// Function prototypes
int getTotal(int[], int);
int posOfLargest(int[], int);
int posOfSmallest(int[], int);
int getAverage(int, int);

int main()
{

// Constant for the number of salsa types
const int NUM_TYPES = 5;

//
string types[NUM_TYPES] = {"mild ", "medium ", "sweet ", "hot ", "zesty "};

int sales[NUM_TYPES];

// Total number of jars
int totalJarsSold;

// Subscript of the salsa that sold the most
int hiSalesProduct;

// Subscript of the salsa that sold the least
int loSalesProduct;

// Average number of jars sold
int averageSales;

// Get number of jars sold for each type of salsa
for (int type = 0; type < NUM_TYPES; type++) {

    // Get the number of jars sold
    cout << "Jars sold last month of " << types[type] << ": ";
    cin >> sales[type];
    
    // Validate the input

    while(sales[type] < 0) {

        cout << "Cannot input a negative value. Please re-enter: ";
        cin >> sales[type]; 
    }
}

// Get total sales and high and low selling products
totalJarsSold = getTotal(sales, NUM_TYPES);
hiSalesProduct = posOfLargest(sales, NUM_TYPES);
loSalesProduct = posOfSmallest(sales, NUM_TYPES);
averageSales = getAverage(totalJarsSold, NUM_TYPES);


// Display the sales report header
cout << endl << endl;
cout << "    Salsa Sales report \n\n";
cout << "Name                   Jars Sold\n";
cout << "________________________________\n";

// Display the name and jars sold of each type.
for (int salsaType=0; salsaType < NUM_TYPES; salsaType++) {

    cout << types[salsaType]
    << setw(21) << sales[salsaType] 
    << endl;
}

// Display the total sales, highest seller, and lowest seller.
cout << "\nTotal Sales:"<<setw(15)<<totalJarsSold<<endl;
cout<<"High Seller:"<<types[hiSalesProduct]<<endl;
cout<<"Low Seller:"<<types[loSalesProduct]<<endl;
cout<<"Average Number of Jars sold:"<<averageSales<<endl;

return 0;
}

int getTotal(int *sales, const int numTypes){

    int total = 0;

    for(int i = 0; i < numTypes; i++) {

        total += sales[i];
    }

    return total;
}

int posOfSmallest(int *sales, int numTypes) {

    int indexOfSmallest = 0;

    for(int i = 0; i < numTypes; i++) {

        if(sales[i] < sales[indexOfSmallest]) {
            indexOfSmallest = i;
        }
    }
    
    return indexOfSmallest;
}

int posOfLargest(int *sales, int numTypes) {

    int indexOfLargest = 0;

    for(int i = 0; i < numTypes; i++) {

        if(sales[i] > sales[indexOfLargest]) {
            indexOfLargest = i;
        }
    }

    return indexOfLargest;
}

int getAverage(int total, int numTypes) {

    return total / numTypes;
}
