#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Dynamic array (vector)
    vector<int> scores = {95, 88, 76, 89, 92};

    // Add the number 100 to the end of the list
    scores.push_back(100);

    cout << "Updated Scores:\n";
    
    for (int i = 0; i < scores.size(); i++) {

        cout << "Student " << i+1 << ": " << scores[i] << "\n";
    }

    return 0;
}
