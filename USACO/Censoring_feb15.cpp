#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>


int main() {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    /* Read input strings. */
    string line, text;
    cin >> line >> text;
    string res;
    for(int i=0; i<line.size(); i++) {
        res +=line[i];
        if(res.size()>=text.size() && res.substr(res.size()-text.size()) == text) {
            res.resize(res.size()-text.size());
        }
    }
    cout<<res<<endl;
}
