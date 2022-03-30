#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

int main() {
    ifstream fin;
    ofstream fout;
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int row, col;
    cin>>row>>col;
    char spotty[row][col];
    char plain[row][col];
    for(int i=0; i<row; i++) {
        string line;
        cin>>line;
        for(int j=0; j<col; j++) {
            spotty[i][j] = line[j];
        }
    }
    for(int i=0; i<row; i++) {
        string line;
        cin>>line;
        for(int j=0; j<col; j++) {
            plain[i][j] = line[j];
        }
    }
    int count = 0;
    for(int j=0; j<col; j++) {
        int identifiable = true;
        vector<int> cnt(26, 0);
        for(int i=0; i<row; i++ ) {
            cnt[spotty[i][j]-'A']++;
        }
        for(int i=0; i<row; i++ ) {
            if(cnt[plain[i][j]-'A'] > 0) {
                identifiable = false;
                break;
            }
        }
        if(identifiable) count++;
    }
    cout<<count;

}
