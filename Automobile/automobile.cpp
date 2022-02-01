//
// Created by Matthew Li on 1/31/22.
//

#include "automobile.h"

automobile::automobile() {
    make_ = "";
    model_ = "";
    year_ = 0;
    price_ = 0.00;
    stall_ = -1;
}
automobile::automobile(std::string autoMake, std::string autoModel, int autoYear, double autoPrice, int autoStall) {
    make_ = autoMake;
    model_ = autoModel;
    year_ = autoYear;
    price_ = autoPrice;
    stall_ = autoStall;

}

std::string automobile::getMake() {
    return make_;
}

std::string automobile::getModel() {
    return model_;
}
int automobile::getYear() {
    return year_;
}
double automobile::getPrice() {
    return price_;
}
int automobile::getStall() {
    return stall_;
}
void automobile::setStall(int autoStall) {
    stall_ = autoStall;
}
bool automobile::park(bool *lot, int size) {
    for(int i = 0; i<size; i++) {
        if(!lot[i]) {
            lot[i] = true;
            return lot[i];
        }
    }
    return false;
}