#include "item.h"

// Defines the Item constructor
Item::Item(string name) {
	this->name = name;
	count = 1;
}

// Defines the increment function
void Item::increment() {
	this->count++;
}

// Defines the getters
string Item::getName() {
	return this->name;
}
int Item::getCount() {
	return this->count;
}
