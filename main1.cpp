#include "Temp.h"
#include <iostream>


int main(){
TemperatureConverter t1;
double temp;

std::cout<< "enter a temperature ";
std::cin>>temp;

t1.toCelsius(temp);
t1.toFahrenheit(temp);

std::cout<< "In celsius: "<< t1.toCelsius(temp)<<std::endl;
std::cout<<"In fahrenheit: "<<t1.toFahrenheit(temp)<<std::endl;

return 0;
}
