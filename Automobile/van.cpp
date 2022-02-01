//
// Created by Matthew Li on 2/1/22.
//

#include "van.h"
#include <iostream>

van:: van() {

}
van::van(std::string vanMake, std::string vanModel, int vanYear, double vanPrice, int vanStall,
int vanSeats) : automobile(vanMake, vanModel, vanYear, vanPrice, vanStall) {
    numSeats_ = vanSeats;
}

std::string van::getStall() {
    if(numSeats_<=7) {
       return std::to_string(automobile::getStall());
    } else {
        std::string s = std::to_string(automobile::getStall());
        std::string s2 = std::to_string(automobile::getStall()+1);
        std::string stallOccupied = s+" , "+s2;
        return stallOccupied;
    }
}

int van::getNumSeats() {
    return numSeats_;
}

bool van::park(bool lot[], int size) {
    if(numSeats_ <= 7) {
        return automobile::park(lot, size);
    } else {
        for(int i = 0; i<size-1; i++) {
            if(!lot[i] && !lot[i+1]) {
                lot[i] = true;
                lot[i+1] = true;
                setStall(i);
                return true;
            }
        }
        return false;
    }
}
