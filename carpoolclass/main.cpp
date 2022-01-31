#include <iostream>
#include <vector>
using namespace std;

struct Time{
    int hour;
    int minute;

};

class Carpool {
public:
    string names[5];
    int numPeople;
    Time arrival;

    void print() {
        cout<<"Travelers in the car:"<<endl;
        for(int i = 0; i<numPeople; i++) {
            cout<<names[i]<<endl;
        }
        cout<<"Arrival time: "<<arrival.hour<<":"<<arrival.minute<<endl;
    }
};

Time earlier(Time t1, Time t2);
Carpool combineCarpool(Carpool car1, Carpool car2);


int main() {
    //Traveler names
    string first[] = {"Bill", "Bob"};
    string second[] = {"John", "Joan", "Alice"};
    //setting times
    Time t1, t2;
    t1.hour = 2;
    t1.minute = 15;
    t2.hour = 3;
    t2.minute = 20;
    Carpool c1, c2, c3;
    for(int i = 0; i < 2; i++) {
        c1.names[i] = first[i];
    }
    c1.numPeople = 2;
    c1.arrival = t1;
    for(int i = 0; i < 3; i++) {
        c2.names[i] = second[i];
    }
    c2.numPeople = 3;
    c2.arrival = t2;
    c3 = combineCarpool(c1, c2);
    c3.print();
}
Time earlier(Time t1, Time t2){
    Time ret;
    if(t1.hour == t2.hour){
        if(t1.minute<t2.minute)
            ret = t1;
        else
            ret = t2;
    }
    else if(t1.hour<t2.hour){
        ret = t1;
    }
    else{
        ret = t2;
    }
    return ret;
};

Carpool combineCarpool(Carpool car1, Carpool car2) {
    Carpool car3;
    if(car1.numPeople+car2.numPeople <=5) {
        car3.numPeople = 0;
        for(int i = 0; i<car1.numPeople; i++) {
            car3.names[car3.numPeople++] = car1.names[i];

        }
        for(int i = 0; i < car2.numPeople; i++) {
            car3.names[car3.numPeople++] = car2.names[i];
        }
        car3.arrival = earlier(car1.arrival, car2.arrival);
        return car3;
    }
    else {
        car3.numPeople = 0;
        car3.arrival.hour = 0;
        car3.arrival.minute = 0;
        return car3;
    }
}






