//
// Created by Matthew Li on 2/1/22.
//

#ifndef AUTOMOBILE_VAN_H
#define AUTOMOBILE_VAN_H
#include "automobile.h"

class van: public automobile {
public:
    van();
    van(std::string vanMake, std::string vanModel, int vanYear, double vanPrice, int vanStall,
        int vanSeats);
    std::string getStall();
    int getNumSeats();
    bool park(bool lot[], int size);
private:
    int numSeats_;
};


#endif //AUTOMOBILE_VAN_H
