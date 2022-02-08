//
// Created by Matthew Li on 2/7/22.
//

#include "DynamicBag.h"

DynamicBag::DynamicBag() {
    capacity_ = 0;
    used_ = 0;
    data_ = nullptr;
}
DynamicBag::DynamicBag(int arr[], std::size_t size){
    used_ = size;
    capacity_ = 2*size;
    data_ = new int[capacity_];
    for(std::size_t i = 0; i<used_; i++) {
        data_[i] = arr[i];
    }
}

std::size_t DynamicBag::size() const {
    return used_;
}

DynamicBag::DynamicBag( const DynamicBag& b) {
    capacity_ = b.size();
    used_ = b.size();
    data_ = new int[capacity_];
    for(std::size_t i = 0; i<used_; i++) {
        data_[i] = b[i];
    }
}
void DynamicBag::operator=(const DynamicBag &b) {
    if(this == &b) {
        return;
    }
    delete data_;
    capacity_ = b.size();
    used_ = b.size();
    data_ = new int[capacity_];
    for(std::size_t i = 0; i<used_; i++) {
        data_[i] = b[i];
    }
}
int DynamicBag::operator[](std::size_t pos) const {
    assert(pos<used_);
//    cout<<"pos: "<< pos <<endl;
//    cout<<"data_[pos]: "<< data_[pos]<<endl;
    return data_[pos];
}

DynamicBag::~DynamicBag() {
    delete [] data_;
}

std::size_t DynamicBag::count(int entry) const{
    std::size_t counter = 0;
    for(std::size_t i = 0; i<used_; i++) {
        if(data_[i] == entry) {
            counter++;
        }
    }
    return counter;
}


void DynamicBag::insert(int target) {
    if(used_<capacity_) {
        data_[used_] = target;
//        cout<<"used : " << used_<<endl;
//        cout<<data_[used_]<<endl;
        used_++;
    }
    else {
        if(capacity_ = 0) {
            capacity_ = 1;
        } else {
            capacity_*=2;
            int* temp = new int [capacity_];
            for(std::size_t i = 0; i<used_; i++) {
                temp[i] = data_[i];
            }
            temp[used_] = target;
            cout<<"used: "<< used_<<endl;
            cout<<temp[used_]<<endl;
            used_++;
            delete data_;
            data_ = temp;
        }
    }
}
void DynamicBag::operator+=(const DynamicBag& b) {
    std::size_t totalSize = used_+b.size();
    if(totalSize<capacity_) {
        for(std::size_t i = 0; i<b.size(); i++) {
            data_[used_++] = b[i];
        }
//        cout<<"used : " << used_<<endl;
//        cout<<data_[used_]<<endl;
    }
    else {
        capacity_ = totalSize;
        int *temp = new int[capacity_];
        for (std::size_t i = 0; i < used_; i++) {
            temp[i] = data_[i];
        }
        for(std::size_t i = 0; i<b.size(); i++) {
            temp[used_++] = b[i];
        }
        delete data_;
        data_ = temp;

    }

}
bool DynamicBag::erase_one(int target) {
    std::size_t marker = -1;
    for(std::size_t i = 0; i<used_ && marker == -1; ++i) {
        if(data_[i] == target) {
            marker = i;
        }
    }
    if(marker == -1) {
        return false;
    }
    for(std::size_t i = marker; i<used_-1; i++) {
        data_[i] = data_[i+1];
    }
    used_--;
    if((used_)<capacity_/4) {
        capacity_/=2;
        int* temp = new int[capacity_];
        for(std::size_t i = 0; i<used_; i++) {
            temp[i] = data_[i];
        }
        delete data_;
        data_ = temp;
    }
    return true;
}
std::size_t DynamicBag::erase(int target) {
    std::size_t count = 0;
    while(erase_one(target)) {
        count++;
    }
    return count;
}

DynamicBag operator + (const DynamicBag& a, const DynamicBag& b) {
    DynamicBag c;
    c+=a;
    c+=b;
    return c;
}
std::ostream& operator<<(std::ostream& out, const DynamicBag& b) {
    for(std::size_t i = 0; i<b.size(); i++) {
        out<<b[i]<<" ";
    }
    return out;
}
