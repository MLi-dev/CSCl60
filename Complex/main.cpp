#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
   Complex a(15, 16);
   Complex b(91, 30);
   Complex c(15, 16);
   double ab = a+b;
   cout<<ab<<endl;
   cout<<a.mag()<<endl;
   bool aMatchB = a==b;
   bool aMatchC = a==c;
   cout<<aMatchB<<", "<<aMatchC<<endl;
   cout<<a;
}
