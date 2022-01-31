#include <iostream>
#include "Rational.h"
#include <cassert>
using namespace std;

int main(int argc, char *argv[])
{
    Rational r1 = Rational(1, 2), r2 = Rational(2, 4);
    Rational r5(5, 6);
    Rational r6 = Rational();
    //Rational r7();//CANNOT CALL DEFAULT CONSTRUCTOR THIS WAY!!!
    Rational r7;
    //Multiply r1 and r2
    //Rational r3 = mult(r1, r2);
    Rational r3 = r1+(r2);
    Rational r4 = r1*(r2);
    //Print out the result in a nice format
  //  cout<<r3.numer<<endl;//Gives an error
    cout<<r3.numer()<<"/"<<r3.denom()<<endl;
    Rational mult = r1*=r2;
    cout<<mult.numer()<<"/"<<mult.denom()<<endl;
    Rational mult2 = r5+=r2;
    cout<<mult2.numer()<<"/"<<mult2.denom()<<endl;
    return 0;
}

