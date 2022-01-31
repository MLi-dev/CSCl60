#include <iostream>
#include "biguint.h"
using namespace std;

int main() {
    biguint a("5125");
    biguint b("5127");
    biguint c("5333");
    biguint d("16222");
//    cout<<a[0]<<endl;
//    cout<<b<<endl;
//    a+=b;
//    cout<<a<<endl;
//    biguint aAddB = a+b;
//    cout<<aAddB<<endl;
//   int aCompareB = a.compare(b);
//    cout<<aCompareB<<endl;
//    int cCompareD = c>=d;
//    cout<<cCompareD<<endl; //Expecting false
//    int cLessD = c<=d;
//    cout<<cLessD<<endl; //Expecting false
//    int cNotD = c!=d;
//    cout<<cNotD<<endl; //Expecting false
    d-=c;
    cout<<d<<endl;
    cout<<d-c<<endl;
    cout<<b.toString()<<endl;

    return 0;
}
