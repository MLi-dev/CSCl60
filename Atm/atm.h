//
// Created by Matthew Li on 1/17/22.
//

#ifndef ATM_ATM_H
#define ATM_ATM_H
#include "bankaccount.h"
#include <fstream>
#include <cmath>

class Atm {
private:
    int twenties_;
    int tens_;
    std::pair<int, int> getBills(double amount);
    //pre: amount>= 0
    //post: Returns int pair representing how much money in terms of twenty and ten dollar bills are needed to meet amount.
public:
    Atm();
    Atm(int tw, int te);
    int getTwenties();
    int getTens();

    BankAccount get_cash(double amount, BankAccount b);
    //pre: amount >= 0 and valid BankAccount object (cannot be null).
    //post: Deducts amount of money from account, and returns modified bank account.

    void operator +=(Atm& rhs);
    //pre: rhs is a valid Atm object.
    //post: Will transfer all bills from rhs to Atm.
    void restock(int new20s, int new10s);
    //pre: new20s and new10s must be greater than 0.
    //post: Adds value of new20s and new10s to the Atm which calls restock.
};
    bool operator ==(Atm lhs, Atm rhs);
    //pre: lhs and rhs must be valid Atm objects.
    //post: Returns true if both Atms have same num of twenty AND ten dollar bills. False otherwise.
    std::ostream& operator <<(std::ostream& out, Atm a);
    //pre: a must be a valid Atm object.
    //post: Prints out information about Atm a.


#endif //ATM_ATM_H
