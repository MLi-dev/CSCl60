//Program to demonstrate the way call-by-value parameters
//behave with pointer arguments.
#include <iostream>
#include "PFArrayD.h"
using namespace std;
typedef int* IntArrayPtr;

void testPFArrayD( );
int main( )
{
    cout << "This program tests the class PFArrayD.\n";

    char ans;
    do
    {
        testPFArrayD( );
        cout << "Test again? (y/n) ";
        cin >> ans;
    }while ((ans == 'y') || (ans == 'Y'));

    return 0;
}

void testPFArrayD( )
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);
    PFArrayD temp2(20);

    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";

    double next;
    cin >> next;
    while ((next >= 0) && (!temp.full( )))
    {
        temp.addElement(next);
        cin >> next;
    }

    cout << "You entered the following "
         << temp.getNumberUsed( ) << " numbers:\n";
    int index;
    int count = temp.getNumberUsed( );
    for (index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << endl;
    temp = temp;
    cout << "Temp 2 is: "
         << temp2.getNumberUsed( ) << " numbers:\n";
    int index2;
    int count2 = temp2.getNumberUsed( );
    for (index2 = 0; index2 < count2; index2++)
        cout << temp2[index2] << " ";
    cout << endl;

    cout << "(plus a sentinel value.)\n";
}




