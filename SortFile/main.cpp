#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void selectSort(vector<string> &names, int size); 

void countSort(vector<string> &names, int size); 

int main()
{
	ifstream inStream; 
	ofstream outStream; 
	inStream.open("names.txt"); 
	outStream.open("sortedNames.txt"); 
	int count = 0; 
	vector<string> names(50); 
	string line; 
	while(!inStream.eof()) {
		inStream>>line;
		names[count] = line; 
		count++;
	}
	// selectSort(names, count); Selection sort does not maintain original array order. Initially was Tim->Tony->Tina, after sort 
	countSort(names, count); //Big O of counting sort is O(n). Also maintains original array order. So Tim->Tony->Tina before, still is Tim->Tony->Tina after. 
	//It is now Tony->Tina->Tim. Also, big O is O(n^2), so it is not a good sort function to use here. 
	for(int i = 0; i<count; i++) {
		outStream<<names[i]<<endl;
	}
	inStream.close(); 
	outStream.close(); 
}

void selectSort(vector<string> &names, int size) {
	int n = size; 
	for(int i = 0; i<n; i++) {
		int sIndex = i; 
		char min = names[i][0]; 
		for(int j = i; j<n; j++){
			if(names[j][0]<min) {
				sIndex = j; 
				min = names[j][0];
			}
		}
		string temp = names[sIndex]; 
		names[sIndex] = names[i]; 
		names[i] = temp; 
	}
	
}

void countSort(vector<string> &names, int size) {
	vector<int> cont(26); 
	vector<int> pos(26); 
	vector<string> sortedArray(size); 
	for(int i = 0; i<26; i++) {
		int index = names[i][0]-65; 
		cont[index]++; 
	} 
	pos[0] = 0; 
	for(int i = 1; i<26; i++) {
		pos[i] = pos[i-1]+cont[i-1]; 
	}
	for(int i = 0; i<size; i++) {
		int firstLA = names[i][0]-65; 
		sortedArray[pos[firstLA]] = names[i];
		pos[firstLA]++; 
	}
	names = sortedArray;
}



