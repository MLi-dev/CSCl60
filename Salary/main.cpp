#include <iostream>
using namespace std;
int total = 0;
int salary(int n) {
    if(n == 0) {
        return 50000;
    }
    total = salary(n-1)*1.1+5000;
    return total;
}

int main() {
    int money = salary(3);
    cout<<money<<endl;
    return 0;
}
