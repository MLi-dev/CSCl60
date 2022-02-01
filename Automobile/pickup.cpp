//
// Created by Matthew Li on 2/1/22.
//

#include <iostream>
#include "pickup.h"

double pickup::getHCapacity() {
    return hCapacity_;
}

bool pickup::isExtendedCab() {
    return hasExtendedCab_;
}

pickup::pickup() : automobile(), hCapacity_(0), hasExtendedCab_(false) {

}

pickup::pickup(std::string autoMake, std::string autoModel, int autoYear, double autoPrice, int autoStall,
               double autoHCapacity, bool autoHasExtendedCab) : automobile(autoMake, autoModel, autoYear,  autoPrice, autoStall){
    hCapacity_ = autoHCapacity;
    hasExtendedCab_ = autoHasExtendedCab;
}
std::string pickup::getStall() {
//    std::cout<<"getStall is: "<<automobile::getStall()+1;
    std::string s = std::to_string(automobile::getStall());
    std::string s2 = std::to_string(automobile::getStall()+1);
    std::string stallOccupied = s+" , "+s2;
    return stallOccupied;
}
bool pickup::park(bool *lot, int size) {
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