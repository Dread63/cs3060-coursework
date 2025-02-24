#include <iostream>
using namespace std;

int getMode (int*, int size);
int *makeArray(int size);

int main() {

    // Constant for the array size
    const int SIZE = 11;

    // An array of test values
    int test[SIZE] = {1,2,3,4,4,2,2,1,3,4,5};

    int mode;

    // Get the mode of the test values
    mode = getMode(test, SIZE);

    // Display the mode if any
    if (mode == 1) {

        cout << "The test set has no mode.\n";
    }

    else {

        cout << "\nThe mode of the test set is: "
        << mode << endl;
    }

    return 0;
}

// Function makeArray
int *makeArray(int size) {

    int *ptr = new int[size];

    return ptr;
}

int getMode(int *test, int size) {

    // Variables

    // A pointer to reference a dynamically allocated array to hold the ffrequencies of each value
    int *frequencies = nullptr;

    int mode = -1;
    int highest = 0;
    int element = 0;
    int count = 0;

    frequencies = makeArray(size);

    for (count = 0; count < size; count++) {

        frequencies[count] = 0;
    }

    // Find the frequency of each element in array
    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            if (*(test + j) == *(test + i)) {

                (*(frequencies + i))++;
            }
        }
    }

    // Find the element with the highest frequency, start by assuming the first element has the highest frequency
    highest = *frequencies;
    element = 0;

    // Step through the frequencies array and find the highest value
    for (count = 1; count < size; count++) {

        if(*(frequencies + count) > highest) {

            highest = *(frequencies + count);
            element = count;
        }
    }

    frequencies = nullptr;

    // If there is no mode (no element has a frequency greater than 1), then return -1.
    // Otherwise return the element with the greatest frequency.
    if (highest > 1) {

        mode = *(test + element);
    }

    return mode;
}