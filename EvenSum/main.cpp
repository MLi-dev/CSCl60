#include <iostream>
using namespace std;
int EvenSum(int n) {
    if(n == 0) {
        return 0;
    }
    return 2*n + EvenSum(n-1);
}

int ncounter(int a[], int size, int n) {
    if(size == 0) {
        return 0;
    }
    if(a[size-1] == n) {
        return 1+ ncounter(a, size-1, n);
    } else {
        return ncounter(a, size-1, n);
    }
}

bool appears(int arr[], int arrsize, int find[], int fsize) {
    if(fsize<1) {
        return true;
    } else if(arrsize < 1 && fsize>=1) {
        return false;
    }
    if(find[fsize-1] == arr[arrsize-1]) {
       return appears(arr, arrsize-1, find, fsize-1);
    } else {
        return appears(arr, arrsize-1, find, fsize);
    }
}

int main() {
    cout<<EvenSum(5)<<endl;
    int a[7] = {3, 7, 8, 2, 1, 3, 9};
    int b[3] = {3, 2, 9};
    cout<<ncounter(a, 7, 3)<<endl;
    cout<<appears(a, 7, b, 3)<<endl;
    int test[6] = { 5, 2, 9, 7, 1, 5};
    int in[4] = {4, 2, 7, 1};
    cout<<appears(test, 6, in, 4 )<<endl;
}
