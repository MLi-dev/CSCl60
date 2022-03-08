#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main() {
   vector<string> orderServed;
    ifstream fin;
    ofstream fout;
    fin.open("Names.txt");
    if(fin.fail()) {
        cout<<"Input file opening failed!"<<endl;
        exit(1);
    }
    fout.open("outfile.txt");
    char next;
    string name = "";
    while(!fin.eof()) {
        fin.get(next);
        if(next == '\n') {
            if(name.size() > 0) {
                orderServed.push_back(name);
                name = "";
            }
        } else {
            name += next;
        }
    }
    for(int i = 0; i<orderServed.size(); i++) {
        fout<<i+1<<". "<<orderServed[i]<<endl;
    }
    fin.close();
    fout.close();
}


