#include<iostream>
#include "TestScores.h"
#include "NegativeScore.h"

// Constant for number of test scores
const int NUM_SCORES = 5;

// Constructor
TestScores::TestScores(int scoreArray[], int size) {

    // Assign numScores
    numScores = size;

    // Allocate memory for the array
    scores = new int[size];

    // Copy the array
    for (int index = 0; index < size; index++) {

        if (scoreArray[index] < 0)
        throw NegativeScore(scoreArray[index]);
        else
        scores[index] = scoreArray[index];
    }
}

// getAverage function
double TestScores::getAverage() const {

    int total = 0;

    for (int index = 0; index < numScores; index++) {

        total += scores[index];
    }

    return static_cast<double>(total) / numScores;
}

int main() {

    try {

        // Create an array of valid scores
        int myScores[NUM_SCORES] = { 88, 90, 93, 87, 99};

        // Create a TestScores object
        TestScores myTestScores(myScores, NUM_SCORES);

        // Display the average
        cout << "The average score is: " << myTestScores.getAverage() << endl;

        // Create an arary with an invalid score
        int badScores[NUM_SCORES] = { 88, 99, -99, 87, 99};

        // Create a TestScores object
        TestScores badTestScores(badScores, NUM_SCORES);

        // Display the average
        cout << "The average score is: " << badTestScores.getAverage() << endl;
    }

    catch (NegativeScore e) {

        cout << "An invlaid score was found. The invalid score is: " << e.getScore() << endl;
    }

    return 0;
}