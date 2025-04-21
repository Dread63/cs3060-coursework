#include<iostream>
#include<string>

using namespace std;

class Instrument {

    private:

        string type;
    
    public:

        // Single argument constructor
        Instrument(string t) : type(t) {

            cout<<"Instrument constructor called\n";
        }

        // Copy constructor
        Instrument(const Instrument& rhs);

        // Assignment operator being overloaded
        Instrument& operator=(const Instrument& rhs); 
};

class Guitar : public Instrument {

    private:

        int strings;

    public:

        // Single argument constructor
        Guitar(string t, int s);

        // Copy constructor
        Guitar(const Guitar& rhs);

        Guitar& operator=(const Guitar& rhs);
};

int main() {

    Guitar g1("string", 6);
    Guitar g2=g1;
    Guitar g3("String", 12);
    g3=g2;
}