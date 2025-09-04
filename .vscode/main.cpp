#include <iostream>
#include <sstream>
#include <vector>
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::stringstream ss(line);
    std::vector<int> nums;
    int x;
    while (ss >> x) {
        nums.push_back(x);
    }

    QuickSort sorter;
    nums = sorter.sort(nums);

    RecursiveBinarySearch rbs;
    bool found = rbs.search(nums, 1);

    std::cout << (found ? "true " : "false ");
    for (size_t i = 0; i < nums.size(); i++) {
        std::cout << nums[i];
        if (i < nums.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}
