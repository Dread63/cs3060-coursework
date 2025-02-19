#include<iostream>
#include<string>

using namespace std;

int main() {

    int x;
    x = 12;

    int *ptr;
    ptr = &x;

    // Value stored in the memory location pointed to by ptr
    cout << *ptr;

    // Value of ptr
    cout << ptr;

    // Dereferencing 5
    *ptr = 5;

    // Chaning the inside the "box" memory location that the pointer points to
    cout << ptr;

    char ch;
    ch = 'A';

    char *q;
    q = &ch;

    *q = 'Z';
    char *p;

    // Making both pointers point to the address in q (the value ch)
    p=q; // Both point to 'A' and 'Z' is lost

    char msg[] = "Hello";

    char *sPtr;

    sPtr = msg;

    *sPtr = 'M';

    sPtr++;

    *sPtr = 'a';
}