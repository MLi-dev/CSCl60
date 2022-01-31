//
// Created by Matthew Li on 1/18/22.
//

#ifndef BIGUINT_BIGUINT_H
#define BIGUINT_BIGUINT_H


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
    biguint(const std::string& a);

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

    // pre: none
    // post: b is subtracted from this biguint. If the difference is a negative, then return 0.
    void operator -= (const biguint & b);

    //pre: none
    //post: will convert the biguint that calls it into a string, by converting its contents into characters and adding to a bigger string.
    std::string toString();

private:

    unsigned short data_[CAPACITY];

    // INVARIANTS:
    //    data_[i] holds the i^th digit of this biguint or 0 if not used
    //    data_[0] holds the least significant (units) digit
};

// nonmember functions

//pre: none
//post: Will return the sum of the two biguints as a new biguint. If the corresponding digits add up to a number >=10, then carry the tens digit over.
biguint operator + (const biguint &a, const biguint &b);

//pre: none
//post: Will return the difference of biguints a and b. If the corresponding digits subtract into a negative number, then you must add a 10 and subtract from the next place up.
biguint operator - (const biguint &a, const biguint &b);

//pre: none (applies for all of them).
//post: Refers to the "compare" function. If "compare" returns -1 (means a<b), return true. Else, return false.
bool operator < (const biguint &a, const biguint &b);
//post: Refers to the "compare" function. If "compare" returns -1 (means a<b) or 0 (a==b), return true. Else, return false.
bool operator <= (const biguint &a, const biguint &b);
//post: Refers to the "compare" function. If "compare" does not return 0, return true. Else, return false.
bool operator != (const biguint &a, const biguint &b);
//post: Refers to the "compare" function. If "compare" returns 0 (a==b), return true. Else, return false.
bool operator == (const biguint &a, const biguint &b);
//post: Refers to the "compare" function. If "compare" returns 1 (a>b) or 0 (a==b), return true. Else, return false.
bool operator >= (const biguint &a, const biguint &b);
//post: Refers to the "compare" function. If "compare" returns 1(a>b), return true. Else, return false.
bool operator > (const biguint &a, const biguint &b);
//pre: none
//post: Prints out the contents of the array in biguint b.
std::ostream& operator <<(std::ostream& out, const biguint&b);



#endif //BIGUINT_BIGUINT_H
