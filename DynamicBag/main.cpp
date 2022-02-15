#include <iostream>
#include "DynamicBag.h"
#include "dUSet.h"

int main() {
//    int arr[3] = {1, 2, 3,};
//    int sizeArr = 3;
//    DynamicBag d1(arr, sizeArr);
    int arr2[11] = {3, 4, 5, 3, 7, 3, 9, 9, 8, 3, 10};
    int sizeArr2 = 11;
    DynamicBag d2(arr2, sizeArr2);
//    cout<<endl;
//    d1+=d2;
//    cout<<d1<<endl;
//    cout<<d1.erase_one(3)<<endl;
//    cout<<d1<<endl;
    dUSet dU1(d2);
    dU1.insert(6);
    cout<<dU1<<endl;
}
