#include <iostream>

#include <string>

using namespace std;

class Appliance {

public:

    // Creating placeholder to be overridden, so Appliance doesn't have it's own use function
    virtual void use() = 0; // Pure virtual

    virtual ~Appliance() {

        cout << "Appliance destroyed\n";

    }

};

class Blender : public Appliance {


    private:

        int blades;

    public:

        Blender(int b = 2) : blades(b) {

            cout << "Blender constructed: " << blades << endl;
        }

        Blender(const Blender& rhs) {

            blades = rhs.blades;

            cout << "Blender copy constructed: " << blades << endl;
        }
        
        Blender& operator=(const Blender& rhs) {

            if (this != &rhs) {

                blades = rhs.blades;
            }

            cout << "Toaster assignment operator: " << blades << endl;

            return *this;
        }

        void use() override {

            cout << "Blending a smoothie... " << endl;
        }

        ~Blender() {

            cout << "Blender destoryed: " << endl;
        }
};

class Toaster : public Appliance {

private:

    string brand;

public:

    Toaster(string b = "DefaultToaster") : brand(b) {

        cout << "Toaster constructed: " << brand << endl;

    }

    Toaster(const Toaster& rhs) {

        brand = rhs.brand;

        cout << "Toaster copy constructed: " << brand << endl;

    }

    Toaster& operator=(const Toaster& rhs) {

        if (this != &rhs) {

            brand = rhs.brand;

        }

        cout << "Toaster assignment operator: " << brand << endl;

        return *this;

    }

    void use() override {

        cout << "Toasting bread..." << endl;

    }

    ~Toaster() {

        cout << "Toaster destroyed: " << brand << endl;

    }

};

 

int main() {

    // Array of pointers to appliance
    Appliance* kitchen[2];

    kitchen[0] = new Toaster("KitchenAid");

    kitchen[1] = new Blender(5);

    // Calling the use function on each appliance in the array
    for (int i = 0; i < 2; ++i) {

        kitchen[i]->use();

    }

    // Call destructor for each appliance in the array
    for (int i = 0; i < 2; ++i) {

        delete kitchen[i];  // Check for proper virtual destructor behavior

    }

    return 0;

}