#include <iostream>
#include <vector>
#include <fstream>
#include "item.h"
using namespace std;

// Declares the GroceryList class
class GroceryList {
	public:
		// Declares all public functions
		void addItem(string itemName);
		Item* getItem(string name);
		vector<Item*> *getList();
		void standardPrint();
		void histogram();
		int query();
		
	private:
		// Declares the private itemList variable
		vector<Item*> itemList;
		
		// Declares private utility function
		string makeIndicator(char c, Item *item);
};
