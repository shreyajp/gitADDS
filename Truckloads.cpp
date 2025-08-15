#include "Truckloads.h"

Truckloads::Truckloads() {}

int Truckloads::numTrucks(int numCrates, int loadSize) {
    if (numCrates <= loadSize) {
        return 1; 
    }

    int leftPile = numCrates / 2;
    int rightPile = numCrates - leftPile;

    return numTrucks(leftPile, loadSize) + numTrucks(rightPile, loadSize);
}
