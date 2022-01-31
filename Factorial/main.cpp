#include <iostream>
using namespace std;

int fact(int n);

int main() {
    cout<<fact(5)<<endl;
    int total = 1;
    int num = 5;
    while(num > 0) {
        total*=num;
        num--;
    }
    cout<<total<<endl;
}

int fact(int n) {
    if(n==1) {
        return 1;
    } else {
        return n*fact(n-1);
    }
}
