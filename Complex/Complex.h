//
// Created by Matthew Li on 1/20/22.
//

#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H
#include <fstream>
#include <cmath>

class Complex {
private:
    double a_;
    double b_;
public:
    Complex();
    Complex(double n1, double n2);
    double getA();
    double getB();
    double mag();

};
    double operator+(Complex c1, Complex c2);
    bool operator==(Complex c1, Complex c2);
    std::ostream& operator<<(std::ostream& out, Complex c);


#endif //COMPLEX_COMPLEX_H
