#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Money
{
public:
    Money();
    Money(double amount);
    Money(int theDollars, int theCents);
    Money(int theDollars);
    double getAmount() const;
    int getDollars() const;
    int getCents() const;
    void input();
    void output() const;
private:
    int dollars;
    int cents;
    int dollarsPart(double amount) const;
    int centsParts(double amount) const;
    int round(double number) const;
};

const Money operator +(const Money& amount1, const Money& amount2);
const Money operator -(const Money& amount1, const Money& amount2);
bool operator ==(const Money& amount1, const Money& amount2);
const Money operator -(const Money& amount);

int main() {
    Money yourAmount, myAmount(10, 9);
    cout<<"Enter an amount of money: ";
    yourAmount.input();
    cout<<endl;
    cout<<"My amount is ";
    myAmount.output();
    cout<<endl;
    if(yourAmount == myAmount) {
        cout<<"We have the same amounts.\n";
    } else {
        cout<<"One of us is richer. \n";
        Money ourAmount = yourAmount + myAmount;
        yourAmount.output();
        cout<<"+";
        myAmount.output();
        cout<<"equals";
        ourAmount.output();
        cout<<endl;
        Money diffAmount = yourAmount - myAmount;
        yourAmount.output();
        cout<<" - ";
        myAmount.output();
        cout<<" equals ";
        diffAmount.output();
        cout<<endl;
        return 0;
    }
}

const Money operator +(const Money& amount1, const Money& amount2) {
    int allCents1 = amount1.getCents() + amount1.getDollars() * 100;
    int allCents2 = amount2.getCents() + amount2.getDollars() * 100;
    int sumAllCents = allCents1 + allCents2;
    int absAllCents = abs(sumAllCents);
    int finalDollars = absAllCents/100;
    int finalCents = absAllCents%100;

    if(sumAllCents < 0) {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }
    return Money(finalDollars, finalCents);
}

const Money operator -(const Money& amount1, const Money& amount2) {
    int allCents1 = amount1.getCents() + amount1.getDollars() * 100;
    int allCents2 = amount2.getCents() + amount2.getDollars() * 100;
    int diffAllCents = allCents1 - allCents2;
    int absAllCents = abs(diffAllCents);
    int finalDollars = absAllCents/100;
    int finalCents = absAllCents%100;

    if(diffAllCents < 0) {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }
    return Money(finalDollars, finalCents);
}

bool operator ==(const Money& amount1, const Money& amount2) {
    return ((amount1.getDollars() == amount2.getDollars()) && (amount1.getCents() == amount2.getCents()));
}

const Money operator -(const Money& amount) {
    return Money(-amount.getDollars(), -amount.getCents());
}

Money::Money(): dollars(0), cents(0) {
}

Money::Money(double amount):dollars(dollarsPart(amount)), cents(centsPart(amount))
