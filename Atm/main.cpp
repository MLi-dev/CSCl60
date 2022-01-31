#include <iostream>
#include "bankaccount.h"
#include "atm.h"
using namespace std;

int main()
{
    Atm a(100, 100);
//    pair<int, int> aPair =  a.getBills(10);
//    cout<<aPair.first<<", "<<aPair.second<<endl;
//    BankAccount b1(1234, 10000.0, 139, "Matthew");
//    BankAccount newba = a.get_cash(50.0, b1);
//    cout<<newba.get_balance()<<endl;
    Atm b(10, 10);
    a+=b;
    cout<<a.getTwenties()<<" , "<<a.getTens()<<endl;
    a.restock(50, 50);
    cout<<a.getTwenties()<<" , "<<a.getTens()<<endl;
    Atm c(100, 30);
    Atm d(100, 30);
    bool cMatchD = c==d;
    cout<<cMatchD<<endl;
    cout<<c;


    return 0;
}
