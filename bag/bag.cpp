//
// Created by Matthew Li on 1/19/22.
//

#include "bag.h"

void Bag::operator += (const Bag & b) {
    assert(size_+b.size_<=CAPACITY);
    for(std::size_t i = size_; i<CAPACITY; ++i) {
        data_[i] = b[b.size()-i];
    }
}
bool Bag::erase_one(int target) {
    int index;
    bool isErasable;
    for(std::size_t i = 0; i<size_; i++) {
        if(data_[i] == target) {
            index = i;
            break;
        }
    }
    for(std::size_t i = index; i<size_; i++) {
        data_[i] = data_[i+1];
    }
    size_--;
    return isErasable;
}

int Bag::erase(int target) {
    int counter = 0;
    for(std::size_t i = 0; i<size_; i++) {
        if(data_[i] == target) {
            counter++;
            for(std::size_t j = i; i<size_-1; j++) {
                data_[i] = data_[i+1];
            }
        }
    }
    return counter;
}