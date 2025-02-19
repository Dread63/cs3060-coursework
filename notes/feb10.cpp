#include<iostream>

using namespace std;

int main() {

    int x;
    // 1 is assigned to x
    x=1;
    // Definition and assignment
    int z = x; // z is a copy of the value stored in x with a diferrent memory location

    int *iPtr; // Pointer of the type integer

    // Assigns the address of x to the integer pointer x
    iPtr = &x;

    // Assigning the value stored at the memory addres iPtr and places it into y (Dereferencing)
    int y = *iPtr;

    // Dereference the integer pointer which will print the value 1 (integer x)
    printf("The value of *ip is %d\n", *iPtr);

    int a = 100, b = 88, c = 8;
    int *p1 = &a, *p2, *p3 = &c; // Both p2 and p3 stored the address of the variable c

    p2 = &b; // P2 points to b
    p2 = p1; // p2 points to a
    b = *p3; // Assigns b the value of integer c (8)
    *p2 = *p3; // Assign c to a

    cout << a << b << c; // outputs 8, 8, 8

    int *p4, *p5, v1, v2;
    p4 = &v1;

    // Two ways to refer to V1 now
    cout << v1;

    cout << *p4;

    int *p6, *p7;
    p6 = p7; // Make p6 point to where p7 points
    *p6 = *p7; // Makes value pointed to by p6, to the value pointed to by p7
}