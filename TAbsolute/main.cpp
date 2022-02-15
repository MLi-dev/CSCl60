#include <iostream>
using namespace std;
#include <string>

//The operation supports ints, doubles, float, long, any numeric type will work.
//Cannot use strings or char. 
template <typename T>
T abs(T a, T b) {
    if(a>b) {
        return a-b;
    }
    return b-a;
}

int main() {
   cout<<abs(5, 5)<<endl;
   cout<<abs(5.6, 5.5)<<endl;
}
