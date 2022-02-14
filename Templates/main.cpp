#include <iostream>
#include <string>
using namespace std;
template<typename T1, typename T2>
int count_exact(T1 a[], T2 size, T1 find) {
    int count = 0;
    for(T2 i = 0; i<size; i++) {
        if(a[i] == find) {
            count++;
        }
    }
    return count;
}
template<typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high) {
    int count = 0;
    for(int i = 0; i<size; i++) {
        if(a[i]>=low && a[i] <= high) {
            count++;
        }
    }
    return count;
}
int main() {
    int a[6] = {6, 2, 3, 2, 6, 2};
    int n = count_exact(a, 6, 2);
    cout<<n<<endl;
    string b[] = {"A", "B", "A", "B", "A", "A"};
    string strFind = "A";
    cout<<count_exact(b, 6, strFind)<<endl;
    int num[6] = {6, 2, 3, 2, 6, 2};
    int c = count_range(num, 6, 2, 4);
    cout<<c<<endl;


}
