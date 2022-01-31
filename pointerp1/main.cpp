#include <iostream>
using namespace std;

//pre: Requires two pointers.
//post: Will switch the values pointers a and b point at.
void swap(int *a, int *b);

int main() {
    //Draw the memory picture for the code below, up until the next comment
  int a, b, *x, *y;
  a = 10;
  b = 5;
  x = &a;
  y = &b;
    cout<<"a is: "<<a<<", b is: "<<b<<endl;
    cout<<"*x is: "<<*x<<", *y is: "<<*y<<endl;
    swap(x, y);
    cout<<"a is: "<<a<<", b is: "<<b<<endl;
    cout<<"*x is: "<<*x<<", *y is: "<<*y<<endl;
    return 0;


    return 0;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
