//
// Created by Matthew Li on 1/31/22.
//

#ifndef AUTOMOBILE_AUTOMOBILE_H
#define AUTOMOBILE_AUTOMOBILE_H
#include <string>


class automobile {
public:
    automobile();
    automobile(std::string autoMake, std::string autoModel, int autoYear, double autoPrice, int autoStall);
    std::string getMake();
    std::string getModel();
    int getYear();
    double getPrice();
    int getStall();
    void setStall(int autoStall);
    bool park(bool lot[], int size);
private:
    std::string make_;
    std::string model_;
    int year_;
    double price_;
    int stall_;

};


#endif //AUTOMOBILE_AUTOMOBILE_H
