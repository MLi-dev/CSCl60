//
// Created by Matthew Li on 1/17/22.
//

#include "atm.h"
Atm:: Atm() {
    twenties_ = 0;
    tens_ = 0;
}

Atm::Atm(int tw, int te) {
    twenties_ = tw;
    tens_ = te;
}

int Atm::getTwenties() {
    return twenties_;
}
int Atm::getTens() {
    return tens_;
}

BankAccount Atm::get_cash(double amount, BankAccount b) {
    if(amount > 0 && amount<b.get_balance() && std::fmod(amount, 10) == 0) {
        try {
            std::pair<int, int> billPair = getBills(amount);
            std::cout << "You will get " << billPair.first << " twenty dollar bills, and will get " << billPair.second
                      << " ten dollar bills." << std::endl;
            b.withdraw(amount);
        } catch(std::invalid_argument e) {
            std::cout<<"Atm doesn't have enough bills"<<std::endl;
        }
    } else {
        std::cout<<"Please enter a valid amount"<<std::endl;
    }
    return b;
}

std::pair<int, int> Atm::getBills(double amount) {
    std::pair<int, int> billsTotal;
    int i = 0;
    while(i<amount) {
        if(amount-i>=20 && twenties_>0) {
            twenties_--;
            billsTotal.first++;
            i = i+20;
        } else if(amount-i>=10 && tens_>0) {
            tens_--;
            billsTotal.second++;
            i = i+10;
        } else {
            throw std::invalid_argument("Atm doesn't have enough bills");
        }
    }
    return billsTotal;
}

void Atm::operator+=(Atm &rhs) {
    twenties_ = twenties_ + rhs.getTwenties();
    tens_ = tens_ + rhs.getTens();
}
void Atm::restock(int new20s, int new10s) {
    twenties_ = twenties_ + new20s;
    tens_ = tens_ + new10s;
}
bool operator ==(Atm lhs, Atm rhs) {
    if(lhs.getTwenties() == rhs.getTwenties() && lhs.getTens() == rhs.getTens()) {
        return true;
    }
    return false;
}
std::ostream& operator <<(std::ostream& out, Atm a) {
    out<<"Twenty bills: "<<a.getTwenties()<<" Ten bills: "<<a.getTens()<<std::endl;
}