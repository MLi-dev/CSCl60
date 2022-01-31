//
// Created by Matthew Li on 1/20/22.
//

#include "Sd.h"

Sd::Sd(){
    name_ = "Card";
    capacity_ = 100;
    memUsed_ = 50;
}

Sd::Sd(std::string SdName, int cap, int mem) {
    name_ = SdName;
    capacity_ = cap;
    memUsed_ = mem;
}


std::string Sd::getName() {
    return name_;
}
int Sd::getCapacity() {
    return capacity_;
}
int Sd::getMemUsed() {
    return memUsed_;
}

bool Sd::takePicture() {
    if(capacity_-memUsed_>=50) {
        return true;
    } else {
        return false;
    }
}
void Sd::empty() {
    memUsed_ = 0;
}
bool Sd::dump(Sd& sd) {
    if(capacity_-(memUsed_+sd.getMemUsed()) >= 0) {
        return true;
    } else {
        return false;
    }
}