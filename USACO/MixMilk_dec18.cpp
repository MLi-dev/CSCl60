#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("mixmilk.in");
    fout.open("mixmilk.out");
    vector<int> milks(3, 0);
    vector<int> capacities(3, 0);
    for(int i=0; i<3; i++) {
        fin>>capacities[i];
        fin>>milks[i];
    }
    int curIndex = 0;
    for(int i=0; i<100; i++) {
        int idx1 = curIndex%3;
        int idx2 = (curIndex+1)%3;
        int milkSum = milks[idx1] + milks[idx2];
        if(milkSum<=capacities[idx2]) {
            milks[idx2] = milkSum;
            milks[idx1] = 0;
        } else{
            milks[idx2] = capacities[idx2];
            milks[idx1] = milkSum - capacities[idx2];
        }
        curIndex++;
    }
    for(auto e : milks) {
        fout<<e<<endl;
    }
}
