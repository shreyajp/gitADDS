#include "Finder.h"
#include <string>
#include <vector>

std::vector<int> Finder::findSubstrings(std::string s1, std::string s2) {
    std::vector<int> result;
    if (s2.empty()) return result;

    std::string prefix;
    std::size_t start = 0;           
                                    
    for (std::size_t i = 0; i < s2.size(); ++i) {
        prefix.push_back(s2[i]);

        std::size_t pos = s1.find(prefix, start);

        if (pos == std::string::npos) {
            result.push_back(-1);
            for (std::size_t j = i + 1; j < s2.size(); ++j) result.push_back(-1);
            break;
        } else {
            result.push_back(static_cast<int>(pos));
            start = pos;
        }
    }

    return result;
}
