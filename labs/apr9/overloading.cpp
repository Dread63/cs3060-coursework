#include <iostream>
using namespace std;

class Rational {

    private:
        int n, d; // Numerator and denominator
    
    public:
        // Polymorphic constructor because changes depending on n and d 
        Rational(int numerator = 0, int denominator = 1):n(numerator),d(denominator) {}

        // MEMEBER FUNCTION: overload + (Rational + Rational)
        Rational operator+(const Rational& rhs) const {
            return Rational(n * rhs.d + rhs.n * d, d * rhs.d);

        }

        // FRIEND FUNCTION: overload + (int + Rational)
        friend Rational operator+(int lhs, const Rational& rhs);

        void print() const {

            cout << n << "/" << d << endl;
        }
};


// FRIEND FUNCTION: allows int + Rational
Rational operator+(int lhs, const Rational& rhs) {

    return Rational(lhs * rhs.d + rhs.n, rhs.d);
}

int main() {

    Rational a(1,2); // 1/2
    Rational b(1,3); // 1/3

    Rational c = a + b; // Calls memeber function
    Rational d = 2 + b; // Calls friend function

    cout << "a + b="; c.print(); // Output: 5/6
    cout << "2+b="; d.print(); // Output: 7/3

    return 0;
}