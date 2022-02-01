//
// Created by Matthew Li on 2/1/22.
//

#ifndef AUTOMOBILE_PICKUP_H
#define AUTOMOBILE_PICKUP_H
#include "automobile.h"


class pickup: public automobile  {
public:
    double getHCapacity();
    bool isExtendedCab();
    pickup();
    pickup(std::string autoMake, std::string autoModel, int autoYear, double autoPrice, int autoStall, double autoHCapacity, bool autoHasExtendedCab);
    std::string getStall();
    bool park(bool lot[], int size);
private:
    double hCapacity_;
    bool hasExtendedCab_;

};


#endif //AUTOMOBILE_PICKUP_H
