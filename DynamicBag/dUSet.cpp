//
// Created by Matthew Li on 2/7/22.
//

#include "dUSet.h"

dUSet::dUSet():  DynamicBag() {
}
dUSet::dUSet(const DynamicBag& d) : DynamicBag(d) {
    removeDup(*this);

}

bool dUSet::targetExist(int target) {
    for(std::size_t i = 0; i<size(); i++) {
        if((*this)[i] == target) {
            return true;
        }
    }
    return false;
}

void dUSet::insert(int target) {
    if(!targetExist(target)) {
        DynamicBag::insert(target);
    }
}


void dUSet::removeDup(DynamicBag& b) {
    b.erase_one(3);
    set<int> s;
    for(int i = 0; i<b.size(); i++) {
        s.insert(b[i]);
    }
    int i = 0;
    int arr[s.size()];
    for(auto e:s) {
        arr[i] = e;
        i++;
    }
    DynamicBag dDupless(arr, s.size());
    b = dDupless;
}