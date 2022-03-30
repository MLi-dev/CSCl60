#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    /* Read input strings. */
    int sessions, cows;
    cin >> sessions >> cows;
    int grid[sessions][cows];
    int ranks[sessions][cows];
    for(int i=0; i<sessions; i++) {
        for(int j=0; j<cows; j++) {
            cin>>grid[i][j];
        }
    }
    for(int i=0; i<sessions; i++) {
        for(int j=0; j<cows; j++) {
            ranks[i][grid[i][j]-1] = j;
        }
    }
    int count = 0;
    for(int i=0; i<cows; i++) {
        for(int j=i+1; j<cows; j++) {
            int countIWinJ = 0;
            for(int k=0; k<sessions; k++) {
                if(ranks[k][i] < ranks[k][j]) {
                    countIWinJ++;
                }
            }
            if(countIWinJ==0 || countIWinJ==sessions ) {
                count++;
            }
        }
    }
    cout<<count<<endl;
}
