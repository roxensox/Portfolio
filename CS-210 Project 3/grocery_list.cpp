#include "grocery_list.h"

// Takes in an item name and adds it to the list if it isn't already in the list
void GroceryList::addItem(string itemName) {
	for (Item *i:this->itemList) {
		// If the item is already in the list, this increments the quantity of it
		if (i->getName() == itemName) {
			i->increment();
			return;
		}
	}
	// If it's not in the list, this makes a new item object and adds it to the list
	Item *newItem = new Item(itemName);
	this->itemList.push_back(newItem);
}

// This takes in an item name and returns the matching item from the list
Item* GroceryList::getItem(string name) {
	for (Item *l:this->itemList) {
		if (l->getName() == name) {
			Item *outvar = l;
			return outvar;
		}
	}
	// If the item is not in the list, this returns a null pointer
	return nullptr;
}

// This returns a pointer to the list
vector<Item*> *GroceryList::getList() {
	return &this->itemList;
}

// This prints the list as it appears in frequency.dat
void GroceryList::standardPrint() {
	for (Item* i:this->itemList) {
		string name = i->getName();
		string count = to_string(i->getCount());
		cout << name << " " << count << endl;
	}
	cout << endl;
}

// This prompts the user to give a search term and returns the quantity of the specified item if it exists
int GroceryList::query() {
	cin.exceptions(ios::failbit);
	string item_name;
	cout << "Please input the Item you would like to search for: ";
	// Validates input (invalid input shouldn't be possible anyway)
	try {
		cin >> item_name;
		cout << endl;
	} 
	catch (exception any) {
		cout << "Invalid input." << endl;
		return 1;
	}

	Item* result = this->getItem(item_name);
	// If the item doesn't appear in the list, this informs the user
	if (result == nullptr) {
		cout << endl << "This Item does not appear in the list." << endl << endl;
		return 2;
	} else {
		cout << result->getName() << ": " << result->getCount() << endl << endl;
		return 0;
	}
}

// Outputs the list data as a histogram
void GroceryList::histogram() {
	// Variable to determine the space an item name can take up
	int nameWidth;
	// Loops through each item object pointer in the list
	for (Item *i:*this->getList()) {
		// Uses ternary operator to catch names that are too long
		nameWidth = (i->getName().length() < 15) ? 15 : i->getName().length();
		// Format and output
		cout << left <<  setw(nameWidth) << i->getName() << setw(i->getCount()) << left << this->makeIndicator('*', i) << endl;
	}
	// Add new line to the end of output
	cout << endl;

}

// Makes a histogram bar with a specified character
string GroceryList::makeIndicator(char c, Item *item) {
	int count = item->getCount();
	string outstr = "";
	for (int i = 0; i < count; i++) {
		outstr.push_back(c);
	}
	return outstr;
}

