//
// Created by Matthew Li on 1/17/22.
//

#include "Rational.h"
    Rational::Rational() {
        numer_ = 1;
        denom_ = 1;
    }

    Rational::Rational(int n, int d) {
        numer_ = n;
        denom_ = d;
    }

    int Rational::numer() { return numer_; }

    int Rational::denom() { return denom_; }

    void Rational::set_numer(int n){ numer_ = n;}
    void Rational::set_denom(int d){
        if(d!=0) {
            denom_ = d;
        }
    }

    int Rational::gcd(int n, int d) {
        int sNum = std::min(n, d);
        for(int i = sNum; i>=1; i--) {
            if(n%i == 0 && d%i == 0) {
                return i;
            }
        }
        return 1;
    }

    Rational Rational::reduce(int n, int d) {
        int factor = gcd(n, d);
        return Rational(n/factor, d/factor);
    }

    Rational operator *(Rational a, Rational b) {

        Rational ans;//Note: this causes an error right now.  We'll discuss why first thing Wednesday
        ans.set_numer(a.numer()* b.numer());
        ans.set_denom(a.denom()*b.denom());
        return ans.reduce(ans.numer(), ans.denom());
    }

    Rational Rational::operator *=(Rational a) {
        numer_ = numer_*a.numer();
        denom_ = denom_*a.denom();
        return reduce(numer_, denom_);
    }
    Rational Rational::operator +=(Rational a) {
        numer_ = (numer_*a.denom()) + (denom_*a.numer());
        denom_ = denom_*a.denom();
        return reduce(numer_, denom_);
    }

    Rational operator +(Rational a, Rational b) {
        Rational ans;
        ans.set_numer((a.numer() * b.denom()) + (b.numer() * a.denom()));
        ans.set_denom(a.denom() * b.denom());
        return ans.reduce(ans.numer(), ans.denom());
    }
//    Rational Rational::operator +=(Rational a) {
//        numer_ =
//    }

    bool operator ==(Rational a, Rational b) {
        Rational aRed = a.reduce(a.numer(), a.denom());
        Rational bRed = b.reduce(b.numer(), b.denom());
        if(aRed.numer() == bRed.numer() && aRed.denom() == bRed.denom()) {
            return true;
        } else {
            return false;
        }
    }
