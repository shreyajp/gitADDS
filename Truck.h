#ifndef TRUCK_H
#define TRUCK_H
#include "Delivery.h"

class Truck : public Delivery{
    private:
double baseFee = 0.0;
double distance = 0.0;


    public:
    double calculateCost() override;
    std::string getType() override;

};

#endif