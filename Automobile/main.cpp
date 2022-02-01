#include <iostream>
#include "automobile.h"
using namespace std;
int main() {
    automobile a("Ford", "Subaru", 2001, 1999.99, 4);
    cout<<"Make of a is:"<<a.getMake()<<endl;
    cout<<"Model of a is:"<<a.getModel()<<endl;
    cout<<"Year a was created is:"<<a.getYear()<<endl;
    cout<<"Price of a is:"<<a.getPrice()<<endl;
    cout<<"Stall of a is:"<<a.getStall()<<endl;
    a.setStall(25);
    cout<<"New stall of a is:"<<a.getStall()<<endl;
    bool parkingSpot[15];
    for(int i = 0; i<15; i++) {
        if(i%2 == 0) {
            parkingSpot[i] = true;
        } else {
            parkingSpot[i] = false;
        }
    }
    for(int i = 0; i<10; i++) {
       cout<<a.park(parkingSpot, 15)<<endl; //parkingSpot array only had 7 available spots, so will return false last 3 times.
    }

}
