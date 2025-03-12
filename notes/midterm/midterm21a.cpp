
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

// Function prototypes
int getTotal(int[], int);
int posOfLargest(int[], int);
int posOfSmallest(int[], int);
int getAverage(int, int);
double getPercentage(int, int);

int main()
{

// Constant for the number of salsa types
const int NUM_TYPES = 5;

//
string types[NUM_TYPES] = {"Standard ", "Heavy-duty ", "Lithium-Ion ", "AGM ", "Performance "};

int sales[NUM_TYPES];

// Total number of batteries sold
int totalBatteriesSold;

// Subscript of the battery that sold the most
int hiSalesProduct;

// Subscript of the battery that sold the least
int loSalesProduct;

// Average number of batteries sold
int averageSales;

// Get number of batteries sold for each type of battery
for (int type = 0; type < NUM_TYPES; type++) {

    // Get the number of batteries sold
    cout << "Enter the number of " << types[type] << " batteries sold: ";
    cin >> sales[type];
    
    // Validate the input

    while(sales[type] < 0) {

        cout << "Cannot input a negative value. Please re-enter: ";
        cin >> sales[type]; 
    }
}

// Get total sales and high and low selling products
totalBatteriesSold = getTotal(sales, NUM_TYPES);
hiSalesProduct = posOfLargest(sales, NUM_TYPES);
loSalesProduct = posOfSmallest(sales, NUM_TYPES);
averageSales = getAverage(totalBatteriesSold, NUM_TYPES);


// Display the sales report header
cout << endl << endl;
cout << "     Battery Sales report     \n\n";
cout << "Name              Batteries Sold\n";
cout << "________________________________\n";

// Display the name and jars sold of each type.
for (int batteryType=0; batteryType < NUM_TYPES; batteryType++) {

    cout << types[batteryType]
    << setw(15) << sales[batteryType] 
    << " units "<<endl;
}

// Display the total sales, highest seller, and lowest seller.
cout << "\nTotal Sales:"<<setw(15)<<totalBatteriesSold<<endl;
cout<<"High Seller:"<<types[hiSalesProduct]<<endl;
cout<<"Low Seller:"<<types[loSalesProduct]<<endl;
cout<<"Average Number of Batteries sold:"<<averageSales<<endl;
cout<<endl<<"Sales Percentage Breakdown: "<<endl<<"----------------------"<<endl;

for (int i = 0; i < NUM_TYPES; i++) {

    double percentage = getPercentage(totalBatteriesSold, sales[i]);
    cout<<types[i]<<": "<<percentage<<"% of total sales"<<endl;
}


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

double getPercentage(int total, int sales) {

    double percentage = ((double)sales / (double)total) * 100;
    return percentage;
}
