#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

int main() {
    ifstream fin;
    ofstream fout;
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin>>n;
    int start[n];
    int end[n];
    for(int i=0; i<n; i++) {
        cin>>start[i];
        cin>>end[i];
    }
    vector<int> countArr(1000, 0);
    // count all the current coverage without firing
    for(int i=0; i<n; i++) {
        for(int j=start[i]; j<end[i]; j++) {
            countArr[j]++;
        }
    }
    int maxCovered = 0;
    for(int i=0; i<n; i++) {
        int covered = 0;
        for(int j=start[i]; j<end[i]; j++) {
            countArr[j]--;
        }
        for(int i=0;i<countArr.size(); i++) {
            if(countArr[i]>0) {
                covered++;
            }
        }
        for(int j=start[i]; j<end[i]; j++) {
            countArr[j]++;
        }
        maxCovered = max(maxCovered, covered);
    }
    cout<<maxCovered;
}
