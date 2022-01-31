//
// Created by Matthew Li on 1/17/22.
//

#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H
#include <algorithm>

class Rational {
private:
    int numer_;
    int denom_;
public:
    Rational();
    Rational(int n, int d);
    //pre: Takes in n, d for numerator and denominator (d cannot be 0).
    //post: numer_ set to n, denom_ set to d.
    int numer();
    //pre: none, just needs an object of type Rational to call it.
    //post: will return numerator
    int denom();
    //pre: none, needs an object of type Rational to call it.
    //post: will return denominator.
    void set_numer(int n);
    //pre: numerator n is a real number.
    //post: Will set class numerator to n.
    void set_denom(int d);
    //pre: denominator d cannot be 0.
    //post: Will set class denominator to d.
    Rational reduce(int n, int d);
    //pre: Denominator d cannot be 0.
    //post: Finds the gcd between n and d, creates new Rational object with n and d divided by the gcd.
    int gcd(int n, int d);
    //pre: needs numerator n, denominator d. Denominator cannot be 0.
    //post: Takes the smaller of n and d, then loops decrementing the smaller value until both n%i and d%i are both 0. i is the divisor. Returns biggest i.
    Rational operator *=(Rational a);
    //pre: needs a valid Rational object passed in.
    //post: multiplies numerator and denominator by a's numerator and denominator, then reduce using the reduce function.
    Rational operator +=(Rational a);
    //pre: needs a valid Rational object passed in.
    //post: multiplies numerator's with a's denominator, multiply denominator with a's numerator, then add. Denominators multiplied.

};
Rational operator *(Rational a, Rational b);
//pre: needs two Rational objects passed in.
//post: multiplies numerator and denominator by a's numerator and denominator, then reduce using the reduce function.

Rational operator +(Rational a, Rational b);
//pre: needs two Rational objects passed in.
//post: multiplies b's numerator with a's denominator, multiply b's denominator with a's numerator, then add. Denominators multiplied.

bool operator ==(Rational a, Rational b);
//Needs two Rational objects passed in.
//post: Compares the reduced form of Rationals a and b. If they are equal, return true. Else return false.



#endif //RATIONAL_RATIONAL_H
