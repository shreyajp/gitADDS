#include "Truckloads.h"

int Truckloads::numTrucks(int crates, int truckSize) {
    if (crates <= 0 || truckSize <= 0) {
        return -1; 
    }

     if (crates <= truckSize) {
        return 1;
    }

    int pile1 = (crates + 1) / 2; 
    int pile2 = crates / 2;    

    return numTrucks(pile1, truckSize) + numTrucks(pile2, truckSize);
}
