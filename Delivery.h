#ifndef DELIVERY_H
#define DELIVERY_H
#include <string>

class Delivery{
    private:

    public:
    virtual double calculateCost()=0;
    virtual std::string getType()=0;
};

#endif
