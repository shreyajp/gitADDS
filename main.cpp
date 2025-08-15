#include <iostream>
#include "Truckloads.h"
#include "Reverser.h"

int main() {
    Truckloads t;
    std::cout << "Trucks needed (crates=14, size=3): " << t.numTrucks(14, 3) << std::endl;

    Reverser r;
    std::cout << "Reverse digit 12345: " << r.reverseDigit(12345) << std::endl;
    std::cout << "Reverse string 'hello': " << r.reverseString("hello") << std::endl;

    std::cout << "Reverse digit (-42): " << r.reverseDigit(-42) << std::endl;
    std::cout << "Reverse string '': " << r.reverseString("") << std::endl;

    return 0;
}
