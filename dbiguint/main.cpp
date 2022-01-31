#include <iostream>
#include "dbiguint.h"
using namespace std;

int main() {
    dbiguint a("2");
    dbiguint a2("11");
   // a2.reserve(10);
  //  cout<<a2<<endl;
//    dbiguint a3 = a-a2;
//    cout<<a3<<endl;
      a*=a2;
      cout<<a<<endl;
  //  a-=a2;
 //   cout<<a<<endl;
//    cout<<a;
//    cout<<endl;
//    dbiguint b("10000");
//    dbiguint c("4232");
//    bool bLargeA = a<b;
//    cout<<bLargeA<<endl;
//    bool aEqC = a==c;
//    cout<<aEqC<<endl; //expecting true
//    a+=b;
//    cout<<a;
//    cout<<endl;
//    cout<<a[3]<<endl;
//    a = b;
//    cout<<a<<endl;


}
