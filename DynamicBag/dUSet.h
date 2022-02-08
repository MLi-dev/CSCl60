//
// Created by Matthew Li on 2/7/22.
//

#ifndef DYNAMICBAG_DUSET_H
#define DYNAMICBAG_DUSET_H
#include "DynamicBag.h"
#include <vector>
#include <set>

class dUSet: public DynamicBag {
public:
    dUSet();
    dUSet(const DynamicBag& d);
    void insert(int target);
    bool targetExist(int target);
private:
    void removeDup(DynamicBag& b);
};


#endif //DYNAMICBAG_DUSET_H
