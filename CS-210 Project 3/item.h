#include <iostream>
using namespace std;

// Declares the Item struct
struct Item {
	// Declares the constructor and all public functions
	Item(string name);
	void increment();
	string getName();
	int getCount();
private:
	// Declares the count and name attributes
	int count;
	string name;
};
