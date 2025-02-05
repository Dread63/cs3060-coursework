#include <iostream>
#include <array>
#include <vector>

using namespace std; // Now we don't need std:: prefix

int main() {

    // std required when not using standard name space
    std::array<int,5>myints;
    std::cout<<"sizeof myints: "<<myints.size() << std::endl;
    std::cout<<"sizeof(myints): "<<sizeof(myints) << std::endl;

    // std:: no longer needed since namespace standard is implemented
    array<int,5> myints;
    cout << "sizeof myints: " << myints.size() << endl;
    cout << "sizeof(myints): " << sizeof(myints) << endl;

}