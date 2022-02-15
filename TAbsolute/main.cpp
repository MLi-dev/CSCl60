#include <iostream>
using namespace std;
#include <string>
#include "TAbsolute.h"
#include "TAbsolute.cpp"
using TAbsoluteLi::TAbsolute;

int main() {
   cout<<TAbsoluteLi::absolute(5.6, 5.5)<<endl;
   cout<<TAbsoluteLi::absolute(7, 5)<<endl;
   int arr[6] = {3, 2, 7, 3, 2, 2};
   cout<<TAbsoluteLi::frequent(arr, 6)<<endl;
    int arr2[6] = {1, 1, 1, 1, 3, 6};
    cout<<TAbsoluteLi::frequent(arr2, 6)<<endl;
}
