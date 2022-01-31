#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");
    int n, m;
    fin>>n>>m;
    int rank[10][20];
    int answer = 0;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            int temp;
            fin>>temp;
            rank[i][temp-1] = j+1;
        }
    }
    for(int i = 0; i<m; i++) {
        for(int j = i+1; j<m; j++) {
            int iBeatJ = 0;
            for(int k = 0; k<n; k++) {
                if(rank[k][i]>rank[k][j]) {
                    iBeatJ++;
                }
            }
            if(iBeatJ == 0 || iBeatJ == n) {
                answer++;
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}
