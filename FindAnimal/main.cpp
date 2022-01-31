#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cmath>
#include <exception>
using namespace std;

struct Animal {
	string name; 
	string gender; 
	int age; 
	double price; 
	string species;
};

Animal cheapest(string type, Animal a[], int size);
bool liveTogether(Animal a, Animal b); 
void compatible(Animal a, Animal b);
int main()
{
	Animal a1 = {"Butch", "male", 3, 57.5, "Dog"}; 
	Animal a2 = {"Blue", "male", 10, 57.2, "Dog"};
	Animal a3 = {"Shiro", "male", 10, 2, "Cat"};
	Animal shelter[3] = {a1, a2, a3}; 
	compatible(a1, a2);
	compatible(a1, a3);
	try{
	Animal bestPet = cheapest("Dog", shelter, 3); 
	cout<<bestPet.name<<endl;
	cout<<bestPet.gender<<endl;
	cout<<bestPet.age<<endl;
	cout<<bestPet.price<<endl;
	cout<<bestPet.species<<endl;
	} catch(invalid_argument& e) {
		cout<<e.what()<<endl;
		return -1;
	}
	return 0;
}

Animal cheapest(string type, Animal a[], int size) {
	Animal pet; 
	double min = INT_MAX;  
	for(int i = 0; i<size; i++) {
		if(a[i].species == type) {
			if(a[i].price < min) {
				pet = a[i]; 
				min = a[i].price;
			}
		}
	}
	if(min == INT_MAX) { //Assuming no pet ever reaches that price. 
		throw invalid_argument("Sorry, no pets meet your criteria");
	} else {
		return pet;
	}
}

bool liveTogether(Animal a, Animal b) {
	if(a.species != b.species) {
		return false; 
	} else {
		return true;
	}
}

void compatible(Animal a, Animal b) {
	if(liveTogether(a, b) == 1) {
		cout<<"True"<<endl;
	} else {
		cout<<"False"<<endl;
	}
}