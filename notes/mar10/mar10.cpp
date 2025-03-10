#include <iostream>
#include "myClass.h"

using namespace std;

int main() {

    int n = 10;
    int *p = &n;

    cout << p; // Prints the address of n
    cout << *p; // Prints the value 10

    // NULL POINTER

    // nullPtr is a null pointer without garbage
    int *nullPtr = 0; // Reserve the value of 0 which is called the null pointer (VALID ASSIGNMENT FOR NULL pointer)

    // nullPtr2 contains garbage
    int *nullPtr2; // uninitialized pointer which is declared but not assigned (INVALID ASSIGNMENT FOR NULL POINTER)

    myClass obj;

    return 0;
}
