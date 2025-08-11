#include <iostream>
#include "Temp.h"

double TemperatureConverter::toCelsius(double fahrenheit){
    return (fahrenheit-32)*(5.0/9.0);
}

double TemperatureConverter::toFahrenheit(double celsius){
    return (celsius*(5.0/9.0))+32;
}