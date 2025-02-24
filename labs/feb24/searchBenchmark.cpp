#include<iostream>
#include<array>

using namespace std;

// Global Constants
const int ARRAY_LENGTH = 20;

// Function prototypes
int linearSearchBench(int[], int size, int value);
int binarySearchBench(int[], int size, int value);

int main() {

    int comparisons; // To hold the number of comparisons

    // Initialize an array with 20 integer values
    int intArray[20] = {100, 21, 33, 46, 52, 9, 12, 152, 500, 140, 121, 172, 193, 141, 15, 21, 177, 181, 192, 220};

    // Display the value being searched for
    int targetValue = 21;

    cout << "Value being searched for: " << targetValue << endl;

    sort(intArray);

    // Perform the linear search
    comparisons = linearSearchBench(intArray, ARRAY_LENGTH, targetValue);

    // Display the results of the linear search
    cout << "The linear search made " << comparisons;
    cout << " comparisons.\m";

    // Perform the binary search
    comparisons = binarySearchBench(intArray, ARRAY_LENGTH, targetValue);

    // Display the results of the binary search
    cout << "The binary search made " << comparisons;
    cout << " comparisons.\m";

    return 0;
}

int linearSearchBench(int intArray[], int size, int value) {

    // Found flag initialized to false
    bool found = false;

    // To hold the number of comparisons
    int comparisons = 0;

    // To hold the array index
    int index = 0;

    // Search while the value has not been found, and the index is still in the array bounds
    while(!found && index < size) {

        comparisons++;

        if (intArray[index++] == value) {

            found = true;
        }
    }

    return comparisons;
}

int binarySearchBench (int intArray[], int size, int value) {

    // The found flag, initialized to false.
    bool found = false;

    int first = 0;
    int middle;
    int last = size - 1;
    int comparisons = 0;

    // Search while the value has not been found, and the index is still in the array bounds.
    while (!found && first <= last) {

        // Calculate mid point
        middle = (first + last) / 2;
        comparisons++;

        // Determine if the value is the mid point
        if (intArray[middle] == value) {

            found = true;
        }

        // Determine if the value is in the lower half
        else if (intArray[middle] > value) {

            last = middle - 1;
        }

        // Determine if the value is in the upper half
        else {

            first = middle + 1;
        }
    }

    return comparisons;
}