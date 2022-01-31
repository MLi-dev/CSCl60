#include <iostream>
#include <iterator>
#include <unordered_set>
#include <map>
using namespace std;

int main() {
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(4);
    cout<<s.count(100 )<<endl;
    s.erase(1);
    cout<<s.count(1)<<endl;
    map<int, int> m;
    m[1] = 5;
    m[3] = 14;
    m[2] = 7;
    m[0] = -1;
//    m.erase(2);
    cout<<m[1]<<endl;
    cout<<m.count(7)<<endl; //Returns a true/false value if the value exists in the map, false here
    cout<<m.count(1)<<endl; //True
    cout<<m[2]<<endl; //Erased the value at m[2]. So 0.
    for(auto x:m) {
        cout<<x.first<< " "<<x.second<<endl;
    }
    return 0;
}
