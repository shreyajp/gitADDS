#include "QuickSort.h"
#include <algorithm>

std::vector<int> QuickSort::sort(std::vector<int> list) {
    if (!list.empty()) {
        quicksort(list, 0, list.size() - 1);
    }
    return list;
}

void QuickSort::quicksort(std::vector<int>& list, int low, int high) {
    if (low < high) {
        int pi = partition(list, low, high);
        quicksort(list, low, pi - 1);
        quicksort(list, pi + 1, high);
    }
}

int QuickSort::partition(std::vector<int>& list, int low, int high) {
    // requirement: pivot = third element if length >= 3, otherwise last element
    int pivotIndex;
    if (high - low + 1 >= 3) {
        pivotIndex = low + 2; 
    } else {
        pivotIndex = high;
    }
    int pivot = list[pivotIndex];
    std::swap(list[pivotIndex], list[high]); 

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (list[j] < pivot) {
            i++;
            std::swap(list[i], list[j]);
        }
    }
    std::swap(list[i + 1], list[high]);
    return i + 1;
}
