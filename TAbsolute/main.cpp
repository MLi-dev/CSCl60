#include <iostream>
using namespace std;
#include <string>
#include "TAbsolute.h"
#include "TAbsolute.cpp"
#include <unordered_map>
#include "algorithm"
#include <cmath>
template<typename T1>
bool cmp(pair<T1, int>& a, pair<T1, int>& b) {
    return a.second<b.second;
}

template<class T>
T absolute1(T a, T b) {
    if (a > b) {
        return a - b;
    }
    return b - a;
}

template<typename T1>
T1 frequent(T1 a[], std::size_t size) {
    T1 maxKey;
    int max = INT32_MIN;
    unordered_map<T1, int> aMap;
    for(int i = 0; i<size; i++) {
        aMap[a[i]]++;
    }
    for(auto c:aMap) {
        if(max<c.second) {
            maxKey = c.first;
            max = c.second;
        }
    }
    return maxKey;
}


int main() {
//   cout<<absolute1(5.6, 5.5)<<endl;
//   cout<<absolute1(7, 5)<<endl;
   int arr[6] = {3, 2, 7, 3, 2, 2};
   cout<<frequent(arr, 6)<<endl;
    int arr2[6] = {1, 1, 1, 1, 3, 6};
    cout<<frequent(arr2, 6)<<endl;
}
