#include <iostream>
#include "Temp.h"

double TemperatureConverter::toCelsius(double fahrenheit){
    return (fahrenheit-32)*(5.0/9.0);
}

double TemperatureConverter::toFarenheit(double celsius){
    return (celcius*(5.0/9.0))+32;
}