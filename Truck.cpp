#include "Truck.h"
#include <iostream>

double Truck::calculateCost(){
    double cost;
    cost = baseFee + distance * 2.5;
    return cost;
};

std::string Truck::getType(){
    return "Truck";
}