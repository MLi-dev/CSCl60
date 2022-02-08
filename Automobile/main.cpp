#include <iostream>
#include "automobile.h"
#include "pickup.h"
#include "van.h"
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
       cout<<a.getStall()<<endl; //Tests if the stall changes depending on parking spot.
    }

    pickup p("Ford", "GMC", 2001, 1999.99, 4, 100.4, true);
    cout<<"P's make:"<<p.getMake()<<endl;
    cout<<"P's model:"<<p.getModel()<<endl;
    cout<<"P's year:"<<p.getYear()<<endl;
    cout<<"P's price:"<<p.getPrice()<<endl;
    cout<<"P's stall:"<<p.getStall()<<endl;
    cout<<"P's capacity:"<<p.getHCapacity()<<endl;
    cout<<"Does P have extension? "<<p.isExtendedCab()<<endl;
    bool parkingSpot2[15];
    for(int i = 0; i<15; i++) {
        if(i%3 == 0) {
            parkingSpot2[i] = true;
        } else {
            parkingSpot2[i] = false;
        }
        cout<<parkingSpot2[i]<<", ";
    }
    for(int i = 0; i<10; i++) {
        cout<<p.park(parkingSpot2, 15)<<endl; //parkingSpot array only had 7 available spots, so will return false last 3 times.
        cout<<p.getStall()<<endl; //Tests if the stall changes depending on parking spot.
    }
    van v("ModelT", "Honda", 2003, 4243.99, 5, 8);
    cout<<"V's make:"<<v.getMake()<<endl;
    cout<<"V's model:"<<v.getModel()<<endl;
    cout<<"V's year:"<<v.getYear()<<endl;
    cout<<"V's price:"<<v.getPrice()<<endl;
    cout<<"V's stall:"<<v.getStall()<<endl;
    cout<<"V's seats:"<<v.getNumSeats()<<endl;
    bool parkingSpot3[15];
    for(int i = 0; i<15; i++) {
        if(i%3 == 0) {
            parkingSpot3[i] = true;
        } else {
            parkingSpot3[i] = false;
        }
        cout<<parkingSpot3[i]<<", ";
    }
    for(int i = 0; i<10; i++) {
        cout<<v.park(parkingSpot3, 15)<<endl; //parkingSpot array only had 7 available spots, so will return false last 3 times.
        cout<<v.getStall()<<endl; //Tests if the stall changes depending on parking spot. You want to get to very end and park.
    }
}
