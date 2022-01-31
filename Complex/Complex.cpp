//
// Created by Matthew Li on 1/20/22.
//

#include "Complex.h"

Complex::Complex() {
    a_ = 0;
    b_ = 0;
}

Complex::Complex(double n1, double n2) {
    a_ = n1;
    b_ = n2;
}

double Complex::getA() {
    return a_;
}
double Complex::getB() {
    return b_;
}

double Complex::mag() {
    return sqrt(pow(a_, 2)+pow(b_, 2));
}
double operator+(Complex c1, Complex c2) {
   return c1.getA()+c2.getA()+c1.getB()+c2.getB();
}
bool operator==(Complex c1, Complex c2) {
    if(c1.getA()==c2.getA() && c1.getB() == c2.getB()) {
        return true;
    } else {
        return false;
    }
}
std::ostream& operator<<(std::ostream& out, Complex c) {
    out<<c.getA()<< " + "<<c.getB()<<"i"<<std::endl;
}


