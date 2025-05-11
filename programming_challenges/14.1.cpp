#include <iostream>
using namespace std;

class Numbers
{

private:
    int number;
    string lessThan20[20] = {
        "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

public:
    Numbers(int number) : number(number) {}

    void print() {

        cout<< lessThan20[number];
    }
};

int main()
{

    Numbers num(5);

    num.print();
}