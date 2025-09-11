#include "BigNumCalc.h"
#include <algorithm>

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
    std::list<int> num;
    for (char c : numString) {
        num.push_back(c - '0');
    }
    return num;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int carry = 0;

    while (it1 != num1.rend() || it2 != num2.rend() || carry) {
        int sum = carry;
        if (it1 != num1.rend()) { sum += *it1; ++it1; }
        if (it2 != num2.rend()) { sum += *it2; ++it2; }
        result.push_front(sum % 10);
        carry = sum / 10;
    }
    return result;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int borrow = 0;

    while (it1 != num1.rend()) {
        int diff = *it1 - borrow - (it2 != num2.rend() ? *it2 : 0);
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_front(diff);
        ++it1;
        if (it2 != num2.rend()) ++it2;
    }

    while (result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }

    return result;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    int digit = num2.back(); 
    std::list<int> result;
    int carry = 0;

    for (auto it = num1.rbegin(); it != num1.rend(); ++it) {
        int prod = (*it) * digit + carry;
        result.push_front(prod % 10);
        carry = prod / 10;
    }
    if (carry > 0) result.push_front(carry);

    return result;
}
