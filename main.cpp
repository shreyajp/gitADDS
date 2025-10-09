#include <iostream>
#include "Autocomplete.h"
#include "PrefixMatcher.h"

int main() {
    Autocomplete ac;
    ac.insert("bin");
    ac.insert("ball");
    ac.insert("ballet");

    auto print = [](const std::vector<std::string>& v) {
        std::cout << "[";
        for (size_t i = 0; i < v.size(); ++i) {
            if (i) std::cout << ", ";
            std::cout << v[i];
        }
        std::cout << "]\n";
    };

    print(ac.getSuggestions("b"));     
    print(ac.getSuggestions("ba"));   
    print(ac.getSuggestions("bal"));   
    print(ac.getSuggestions("balle")); 

    PrefixMatcher pm;
    pm.insert("1100110111", 1);
    pm.insert("110011011",  2);
    pm.insert("11001101",   3);

    std::cout << "Best router: " 
              << pm.selectRouter("110011011001") << "\n"; 
}
