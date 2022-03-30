#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//#include <bits/stdc++.h>

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("cbarn.in");
    fout.open("cbarn.out");
    int n = 0;
    fin>>n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) {
        fin>>arr[i];
    }
    int minSum = INT32_MAX;
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int step=1; step<n; step++) {
            int index = (i+step)%n;
            sum +=arr[index] * step;
        }
        minSum = min(minSum, sum);
    }
    fout<<minSum<< endl;
}
