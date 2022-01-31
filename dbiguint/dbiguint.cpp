#include "dbiguint.h"
#include "cassert"
#include <iostream>


dbiguint::dbiguint(){
    data_= new unsigned short[1];
    data_[0] = 0;
    capacity_ = 1;
}

dbiguint::dbiguint(const std::string& a){
    unsigned short b = a.size();
    data_ = new unsigned short[b];
    capacity_ = b;
    unsigned short x = 0;
    for (std::size_t i = b; i>0; --i){
        data_[x] = a[i-1] - 48;
        ++x;
    }
}

std::size_t dbiguint::size() const{
    return capacity_;
}
dbiguint::~dbiguint() {
    delete data_;
}

void dbiguint::operator =(const dbiguint & b) {
    this->size() == b.size();
    data_ = new unsigned short[this->size()];
    for(std::size_t i = 0; i<this->size(); i++) {
        data_[i] = b[i];
    }
}


unsigned short dbiguint::operator[](std::size_t pos) const{
   if(pos<size()) {
       return data_[pos];
   } else {
       return 0;
   }
}


std::ostream& operator<<(std::ostream& out, const dbiguint& b) {
    for(std::size_t i = b.size(); i>0; i--) {
        out<<b[i-1];
    }
    return out;
}

void dbiguint::reserve(std::size_t newcapacity){
    if (capacity_ < newcapacity){
        unsigned short a[capacity_];
        for (std::size_t y = 0; y<capacity_; ++y){
            a[y] = data_[y];
        }
        data_ = new unsigned short[newcapacity];
        for (std::size_t i = 0; i<capacity_; ++i){
            data_[i] = a[i];
        }
        for (std::size_t i = capacity_; i<newcapacity; i++){
            data_[i] = 0;
        }
        capacity_ = newcapacity;
    } else {
        int leadZeroCount=0;
        for(std::size_t i = capacity_-1; i>=0 && data_[i]== 0; --i) {
            leadZeroCount++;
        }
        capacity_ = capacity_-leadZeroCount;
        unsigned short a[capacity_];
        for (std::size_t y = 0; y<capacity_; ++y){
            a[y] = data_[y];
        }
        data_ = new unsigned short[capacity_];
        for (std::size_t i = 0; i<capacity_; ++i){
            data_[i] = a[i];
        }
    }
}

void dbiguint::operator += (const dbiguint & b){
    std::size_t newSize = std::max(size(), b.size());
    reserve(newSize);
    unsigned short y =0;
    std::size_t i = 0;
    int n = b.size();
    while (i != newSize){
        int bValue =i<n? b[i] : 0;
        unsigned short x = data_[i] +bValue + y;
        if (x >= 10){
            x -= 10;
            y = 1;
            data_[i] = x;
        }
        else{
            data_[i] = x;
            y = 0;
        }
        ++i;
    }
    //when y==1, we need to make sure increasing the data capacity
    if(y==1) {
        reserve(newSize + 1);
    }
    data_[i] = data_[i] + y;
}

void dbiguint::operator*=(const dbiguint &b) {
    int aValue = 0;
    int digits = 1;
    for(int i = 0; i<size(); i++) {
        aValue+=data_[i] * digits;
        digits*=10;
    }
    int bValue = 0;
    digits = 1;
    for(int i = 0; i<b.size(); i++) {
        bValue +=b[i]*digits;
        digits*=10;
    }
    int cValue = aValue*bValue;
    std::string s = std::to_string(cValue);
    reserve(s.size());
    int j=0;
    for(int i=size()-1; i>=0; i--) {
        data_[i] = s[j] - 48;
        j++;
    }

}

void dbiguint::operator -=(const dbiguint& b){
    if(this->compare(b) == -1) {
        reserve(1);
        data_[0] = 0;
        return;
    }
    std::size_t newSize = size();
    unsigned short y = 0;
    std::size_t i = 0;
    int n = b.size();
    while(i!=newSize) {
        int bValue = i<n ? b[i]:0;
        short x = data_[i] - bValue - y;
        if(x<0) {
            x+=10;
            y = 1;
        } else {
            y = 0;
        }
        data_[i] = x;
        ++i;
    }
    if(data_[i] == 0) {
        reserve(newSize-1);
    }
}
dbiguint operator + (const dbiguint & a, const dbiguint & b) {
    unsigned short y;
    std::string s = "";
    if(a.size() >= b.size()) {
        for (int i = 0; i < a.size()+1; i++) {
            unsigned short x = a[i] + b[i] + y;
            if (x >= 10) {
                x -= 10;
                y = 1;
            } else {
                y = 0;
            }
            char xChar = x + 48; //This is to convert back to the ASCII for character, since 0's ASCII is 48.
            s = xChar + s;
        }
    } else if(a.size() < b.size()) {
        for (int i = 0; i < b.size()+1; i++) {
            unsigned short x = a[i] + b[i] + y;
            if (x >= 10) {
                x -= 10;
                y = 1;
            } else {
                y = 0;
            }
            char xChar = x + 48; //This is to convert back to the ASCII for character, since 0's ASCII is 48.
            s = xChar + s;
        }
    }
    if(s[0] == '0') {
        s = s.substr(1);
    }
    dbiguint c(s);
    return c;
}

dbiguint operator-(const dbiguint& a, const dbiguint& b) {
//    if(a.compare(b) == -1) {
//        return dbiguint("0");
//    }
    unsigned short y = 0;
    std::string s = "";
    int bSize = b.size();
    for(int i = 0; i<a.size(); i++) {
        int bValue = i<bSize ? b[i] : 0;
        short x = a[i] - bValue - y;
        if(x<0) {
            x+=10;
            y = 1;
        } else {
            y = 0;
        }
        char xChar = x+48;
        s = xChar+s;
    }
    if(s[0] == '0') {
        s = s.substr(1);
    }
    dbiguint c(s);
    return c;
}


int dbiguint::compare(const dbiguint & b) const {
    if(this == &b) {
        return 0;
    }
    std::size_t cap = (size()>b.size()? size(): b.size());
    for(std::size_t i = cap; i>0; i--) {
        if(data_[i-1] > b.data_[i-1]) {
            return 1;
        } else if(data_[i-1] < b.data_[i-1]) {
            //std::cout<<"Matthew"<<std::endl;
            return -1;
        }
    }
    if(data_[0]>b.data_[0]) {
        return 1;
    }
    else if(data_[0]<b.data_[0]) {
        return -1;
    } else {
        return 0;
    }
};

bool operator < (const dbiguint & a, const dbiguint & b) {
    if(a.compare(b) == -1) {
        return true;
    }
    return false;
}
bool operator <= (const dbiguint & a, const dbiguint & b) {
    if(a.compare(b) == -1 || a.compare(b) ==0) {
        return true;
    }
    return false;
}

bool operator > (const dbiguint & a, const dbiguint & b) {
    if(a.compare(b) == 1) {
        return true;
    }
    return false;
}

bool operator >= (const dbiguint & a, const dbiguint & b) {
    if(a.compare(b) == 1 || a.compare(b) ==0) {
        return true;
    }
    return false;
}

bool operator == (const dbiguint & a, const dbiguint & b) {
    if(a.compare(b) == 0) {
        return true;
    }
    return false;
}

bool operator != (const dbiguint & a, const dbiguint & b) {
    if(a.compare(b) != 0) {
        return true;
    }
    return false;
}

