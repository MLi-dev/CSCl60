//Thomas Kelly Matthew Li
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

class ModInt{
private:
    int value_;
    int mod_;

public:
    int value(){ return value_;}
    int mod(){ return mod_ ;}

    ModInt();
    ModInt(int a, int b);
    //pre: mod does not equal 0
    //post: replaces object that calls with itself plus rhs value
    //if same mod, combine values and replace value with new sum
    //if not same mod, replace value and mod with -1
    void operator +=(ModInt rhs);
};

bool operator ==(ModInt lhs, ModInt rhs);
ModInt operator +(ModInt lhs, ModInt rhs);
ModInt operator *(ModInt lhs, ModInt rhs);
bool operator <(ModInt lhs, ModInt rhs);
bool operator >(ModInt lhs, ModInt rhs);
bool operator <=(ModInt lhs, ModInt rhs);
bool operator !=(ModInt lhs, ModInt rhs);
ostream& operator <<(std::ostream& out, ModInt a);

int main(){
    ModInt a = ModInt(3,10);
    ModInt b = ModInt(10,10);
//    a += b;
//    std::cout<<a.value()<<" "<<a.mod()<<std::endl;
    ModInt c = a*b;
    std::cout<<c.value()<<" "<<c.mod()<<std::endl;
    bool TF = a<b;
    std::cout<<TF<<std::endl;
    bool notMatch = a!=b;
    std::cout<<notMatch<<std::endl;
    cout<<a<<endl;


};

ModInt::ModInt(){
    value_ = 0;
    mod_ = 0;
}

ModInt::ModInt(int a, int b){
    value_ = a;
    mod_ = b;
}

bool operator == (ModInt lhs, ModInt rhs){
    if (lhs.value() == rhs.value() && lhs.mod() == rhs.mod()){
        return true;
    }
    else{
        return false;
    }
}

/*
This must be a member function because we want to replace the value of our ModInt object.
The only way to modify an existing class ModInt objects data is by using a member function that
can access our private variables. As seen in question 4/5 we have to return something to do
addition using a non-member function whereas using a member function we can use a void type
since we are just overwriting values.
*/
void ModInt::operator +=(ModInt rhs){
    assert(mod_ != 0 && rhs.mod() != 0);
    if (mod_ == rhs.mod()){
        value_ += rhs.value();
    }
    else{
        value_ = -1;
        mod_ = -1;
    }
}

/* If you want to implement a + operator, you would need to pass in two arguments.
I would start with the framework of my += operator but would need to replace
all of the private variables with getter functions. I would then Initialize a
ModInt object and use a constructor to set it to the sum of the values and the
shared mod. (Assuming it passes if statement) If it does not pass if statement
then we initialize a ModInt object and use the constructor to fill it in with
-1,-1.
*/
ModInt operator +(ModInt lhs, ModInt rhs){
    if (lhs.mod() == rhs.mod()){
        ModInt a(lhs.value() + rhs.value(), lhs.mod());
        return a;
    }
    else{
        ModInt a(-1,-1);
        return a;
    }
}
ModInt operator *(ModInt lhs, ModInt rhs) {
    if(lhs.mod() == rhs.mod()) {
        ModInt a(lhs.value()*rhs.value(), rhs.mod());
        return a;
    } else {
        ModInt a(-1, -1);
        return a;
    }
}
/* Since it is comparing both value and mod, so in the case when a's value>b's value, but the a's mod still <b's mod, in this case
 * It will still return false.*/
bool operator <(ModInt lhs, ModInt rhs) {
    if((lhs.mod()<rhs.mod() && lhs.value() < rhs.value()) || (lhs.mod() ==rhs.mod() && lhs.value() < rhs.value())){
        return true;
    }
    return false;
}
bool operator >(ModInt lhs, ModInt rhs) {
    if((lhs.mod()>rhs.mod() && lhs.value()>rhs.value()) || (lhs.mod() ==rhs.mod() && lhs.value() > rhs.value())){
        return true;
    }
    return false;
}
bool operator <=(ModInt lhs, ModInt rhs) {
    if((lhs.mod()<=rhs.mod() && lhs.value() <= rhs.value()) || (lhs.mod() ==rhs.mod() && lhs.value() <= rhs.value())){
        return true;
    }
    return false;
}
bool operator >=(ModInt lhs, ModInt rhs) {
    if((lhs.mod()>=rhs.mod() && lhs.value()>=rhs.value()) || (lhs.mod() ==rhs.mod() && lhs.value() >= rhs.value())){
        return true;
    }
    return false;
}
bool operator !=(ModInt lhs, ModInt rhs) {
    if(lhs.mod()!=rhs.mod() || lhs.value() != rhs.value()) {
        return true;
    }
    return false;
}
ostream& operator <<(std::ostream& out, ModInt a) {
    out << "The value of a is: "<< a.value()<<", the mod of a is: "<<a.mod()<<endl;
    return out;
}