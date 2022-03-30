#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("shell.in");
    fout.open("shell.out");
    int n;
    fin>>n;
    vector<int> cur(3, 0);
    for(int i=0; i<n; i++) {
        cur[i] = i;
    }
    vector<int> winCnt(3, 0);
    for(int i=0; i<n; i++) {
        int idx1=0, idx2=0;
        fin>>idx1;
        fin>>idx2;
        swap(cur[idx1-1], cur[idx2-1]);
        int guess;
        fin>>guess;
        winCnt[cur[guess-1]]++;
    }
    int maxWin = INT32_MIN;
    for(auto e: winCnt) {
        maxWin = max(maxWin, e);
    }
    fout<<maxWin<<endl;
}
