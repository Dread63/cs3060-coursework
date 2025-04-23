#ifndef TEST_SCORES_H
#define TEST_SCORES_H
#include<iostream>
using namespace std;

class TestScores {

    private:
        int numScores; // Number of scores
        int *scores; // Pointer to array of scores

    public:
        //Default constructor
        TestScores() {
            numScores = 0;
            scores = nullptr;
        }

        // Constructor
        TestScores(int [], int);

        // getAverage function
        double getAverage() const;

};

#endif