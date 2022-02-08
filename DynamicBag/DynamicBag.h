//
// Created by Matthew Li on 2/7/22.
//

#ifndef DYNAMICBAG_DYNAMICBAG_H
#define DYNAMICBAG_DYNAMICBAG_H
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class DynamicBag {
public:
    DynamicBag();
    DynamicBag(int arr[], std::size_t size);
    DynamicBag(const DynamicBag& b);
    ~DynamicBag();
    std::size_t size() const;
    std::size_t count(int entry) const;
    int operator[](std::size_t pos) const;
    void insert(int target);
    void operator+=(const DynamicBag& b);
    bool erase_one(int target);
    std::size_t erase(int target);
    void operator =(const DynamicBag& b);

private:
    int *data_;
    std::size_t capacity_;
    std::size_t used_;

};

DynamicBag operator +(const DynamicBag& a, const DynamicBag& b);
std::ostream& operator<<(std::ostream& out, const DynamicBag& b);

#endif //DYNAMICBAG_DYNAMICBAG_H
