#ifndef NEGATIVE_SCORE_H
#define NEGATIVE_SCORE_H

class NegativeScore {

    private:

        int score;

    public:

        // Constructor
        NegativeScore(int s) : score(0) {

            score = s;
        }

        // Get score function
        int getScore() const {

            return score;
        }

};

#endif
