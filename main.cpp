#include <iostream>
#include "Truckloads.h"
#include "Reverser.h"

int main() {
    Truckloads t;
    std::cout << "Truckloads for 14 crates, load size 3: "
              << t.numTrucks(14, 3) << std::endl;

    Reverser r;
    int number = 12345;
    std::cout << "Reverse of " << number << ": "
              << r.reverseDigit(number) << std::endl;

    std::string word = "hello";
    std::cout << "Reverse of \"" << word << "\": "
              << r.reverseString(word) << std::endl;

    std::cout << "Reverse of negative number: "
              << r.reverseDigit(-123) << std::endl;
    std::cout << "Reverse of empty string: "
              << r.reverseString("") << std::endl;

    return 0;
}
