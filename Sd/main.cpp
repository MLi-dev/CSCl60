#include <iostream>
#include "Sd.h"

int main() {
    Sd a("Casio", 100, 50);
    std::cout<<a.getName()<<", "<<a.getCapacity()<<", "<<a.getMemUsed()<<std::endl;
    Sd b("Apple", 100, 54 );
    std::cout<<b.getName()<<", "<<b.getCapacity()<<", "<<b.getMemUsed()<<std::endl;
    Sd c("Bill", 100, 90 );
    std::cout<<c.takePicture()<<std::endl;
    std::cout<<a.takePicture()<<std::endl;
    std::cout<<a.dump(b)<<std::endl;
}
