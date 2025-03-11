
class myClass {

    private:
        int x,y;
    
    public:

        // CONSTRUCTOR OVERLOADING
        myClass () {

            x = y = 0;
        }

        myClass(int a) {

            x=y=a;
        }

        myClass(int a, int b) {

            x=a;
            y=b;
        }
};