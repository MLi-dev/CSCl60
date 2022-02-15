//
// Created by Matthew Li on 2/15/22.
//

#include "TAbsolute.h"
#include "unordered_map"
namespace TAbsoluteLi {
    template<class T>
    T absolute(T a, T b) {
        if (a > b) {
            return a - b;
        }
        return b - a;
    }

    template<typename T>
    T frequent(T a[], std::size_t size) {
        T maxKey;
        int max = INT32_MIN;
        unordered_map<T, int> aMap;
        for (int i = 0; i < size; i++) {
            aMap[a[i]]++;
        }
        for (auto c: aMap) {
            if (max < c.second) {
                maxKey = c.first;
                max = c.second;
            }
        }
        return maxKey;
    }
}
