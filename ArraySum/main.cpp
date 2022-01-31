#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum(vector<int> &a);
int count(vector<int> a);
int maxValue(vector<int> a);
int binSearch(vector<int> a, int target, int low, int high);
vector<int> quickSort(vector<int> a);
int main() {
       int arr[6] = {-1, 0, 3, 5, 9, 12};
       vector<int> a(arr, arr+6);
     cout<<sum(a)<<endl;
     cout<<count(a)<<endl;
     cout<<maxValue(a)<<endl;
     cout<<binSearch(a, 2, 0, 5)<<endl;
     vector<int> sorted = quickSort(a);
     for(int nums : sorted) {
         cout<<nums<<endl;
     }

    return 0;
}

int sum(vector<int> &a) {
    if(a.size() == 1) {
        return a[0];
    }
    vector<int> b;
    b = vector<int>(a.begin() + 1, a.end());
    return a[0] + sum(b);

}

int count(vector<int> a) {
    if(a.empty()) {
        return 0;
    }
    vector<int> b = vector<int>(a.begin()+1, a.end());
    return 1+count(b);
}
int maxValue(vector<int> a) {
    if(a.size() == 1) {
        return a[0];
    }
    vector<int> b = vector<int>(a.begin()+1, a.end());
    return max(a[0], maxValue(b));
}

int binSearch(vector<int> a, int target, int low, int high) {
    if(low > high) {
        return -1;
    }
    int mid = low+ (high-low)/2;
    if(a[mid] == target) {
        return mid;
    }
    if(a[mid]<target) {
        low = mid+1;
    }
    if(a[mid]>target) {
        high = mid-1;
    }
    return binSearch(a, target, low, high);
}
vector<int> quickSort(vector<int> a) {
    if(a.size()<2) {
        return a;
    }
    int pivot = a[0];
    vector<int> less;
    vector<int> more;
    for(int i = 1; i<a.size(); i++) {
        if(a[i]<pivot) {
            less.push_back(a[i]);
        } else {
            more.push_back(a[i]);
        }
    }
    vector<int> sortedLess = quickSort(less);
    sortedLess.push_back(pivot);
    vector<int> sortedMore = quickSort(more);
    sortedLess.insert(sortedLess.end(), sortedMore.begin(), sortedMore.end());
    return sortedLess;
}

