//
// Created by Matthew Li on 1/18/22.
//

#include "biguint.h"
#include "cassert"

biguint::biguint(){
    for (std::size_t i = 0; i < CAPACITY; i++){
        data_[i] = 0;
    }
}

biguint::biguint(const std::string& a){
    std::size_t y = 0;
    std::size_t x = a.length();
    for (std::size_t i = 0; i < CAPACITY; i++){
        data_[i] = 0;
    }
    while( x > 0){
        unsigned short num = a[x-1] - '0';
        data_[y] = num;
        y++;
        x--;
    }
}

unsigned short biguint::operator [](std::size_t pos) const{
    assert( pos < CAPACITY);
    return data_[pos];
}


std::ostream& operator<<(std::ostream& out, const biguint& b) {
    for(std::size_t i = 20; i>0; i--) {
        out<<b[i-1];
    }
    return out;
}


void biguint::operator += (const biguint & b){
    unsigned short y =0;
    for (int i = 0; i<CAPACITY; i++){
        unsigned short x = data_[i] + b[i] + y;
        if (x >= 10){
            x -= 10;
            y = 1;
        }
        else{
            y = 0;
        }
        data_[i] = x;
    }
}

void biguint::operator -= (const biguint & b) {
    unsigned short y = 0;
    if(this->compare(b) == -1) {
        for (std::size_t i = 0; i < CAPACITY; i++){
            data_[i] = 0;
        }
        return;
    }
    for(int i = 0; i<CAPACITY; i++) {
        short x = data_[i] - b[i] -y;
        if(x < 0) {
            x+=10;
            y = 1;
        } else {
            y = 0;
        }
        data_[i] = x;
    }
}

biguint operator + (const biguint & a, const biguint & b) {
    unsigned short y;
    std::string s = "";
    for(int i = 0; i<20; i++) {
        unsigned short x = a[i] + b[i] + y;
        if (x >= 10) {
            x -= 10;
            y = 1;
        } else {
            y = 0;
        }
        char xChar = x+48; //This is to convert back to the ASCII for character, since 0's ASCII is 48.
        s = xChar + s;
    }
    biguint c(s);
    return c;
}

biguint operator - (const biguint & a, const biguint & b) {
    unsigned short y;
    std::string s = "";
    if(a<b) {
        biguint c;
        return c;
    }
    for(int i = 0; i<20; i++) {
        short x = a[i] - b[i] - y;
        if (x < 0) {
            x += 10;
            y = 1;
        } else {
            y = 0;
        }
        char xChar = x+48;
        s = xChar + s;
    }
    biguint c(s);
    return c;
}


int biguint::compare(const biguint & b) const {
    if(this == &b) {
        return 0;
    }
    std::size_t cap = (CAPACITY>b.CAPACITY ? CAPACITY: b.CAPACITY);
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
    }
    return 0;

};

bool operator < (const biguint &a, const biguint &b) {
    if(a.compare(b) == -1) {
        return true;
    }
    return false;
}
bool operator <= (const biguint &a, const biguint &b) {
    if(a.compare(b) == -1 || a.compare(b) == 0) {
        return true;
    }
    return false;
}
bool operator != (const biguint &a, const biguint &b) {
    if(a.compare(b) != 0) {
        return true;
    }
    return false;
}
bool operator == (const biguint &a, const biguint &b) {
    if(a.compare(b) == 0) {
        return true;
    }
    return false;
}
bool operator >= (const biguint &a, const biguint &b) {
    if(a.compare(b) == 1 || a.compare(b) == 0) {
        return true;
    }
    return false;
}
bool operator > (const biguint &a, const biguint &b) {
    if(a.compare(b) == 1) {
        return true;
    }
    return false;
}

std::string biguint::toString() {
    std::string printUint = "";
    for(std::size_t i = CAPACITY; i>0; i--) {
        char temp = data_[i-1]+48;
        printUint = printUint + temp;
    }
    return printUint;
}






/*

#ifndef BIGUINT_H
#define BIGUINT_H

#include <cstdlib>
#include <iostream>
#include <string>

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 constructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this biguint >, ==, < than given biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//                        <<, >>


class biguint
{
public:
    // CONSTANTS & TYPES

    static const std::size_t CAPACITY = 20;

    // CONSTRUCTORS

    // pre: none
    // post: creates a biguint with value 0
    biguint();

    // pre: s contains only decimal digits
    // post: creates a biguint whose value corresponds to given string of digits
    biguint(const std::string &);

    // CONSTANT MEMBER FUNCTIONS

    // pre: pos < CAPACITY
    // post: returns the digit at position pos
    //          0 is the least significant (units) position

    unsigned short operator [](std::size_t pos) const;

    // pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
    int compare(const biguint & b) const;



    // MODIFICATION MEMBER FUNCTIONS


    // pre: none
    // post: b is added to this biguint; ignore last carry bit if any
    void operator += (const biguint & b);
    void operator -= (const biguint & b);

private:

    unsigned short data_[CAPACITY];

    // INVARIANTS:
    //    data_[i] holds the i^th digit of this biguint or 0 if not used
    //    data_[0] holds the least significant (units) digit
};

// nonmember functions
std::ostream& operator <<(std::ostream& out, const biguint& b);
biguint operator + (const biguint &, const biguint &);
biguint operator - (const biguint &, const biguint &);

bool operator < (const biguint &, const biguint &);
bool operator <= (const biguint &, const biguint &);
bool operator != (const biguint &, const biguint &);
bool operator == (const biguint &, const biguint &);
bool operator >= (const biguint &, const biguint &);
bool operator > (const biguint &, const biguint &);





#endif // BIGUINT_H
*/