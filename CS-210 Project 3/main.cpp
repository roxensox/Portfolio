#include "grocery_list.h"
#include <iostream>
#include <string>

// Utility function prototypes
const string f_name = "CS210_Project_Three_Input_File.txt";
GroceryList* Load_TXT(string f_name);
int menu();
void write_to_dat(vector<Item*> itemList);

int main() {
	// Loads the .txt file into the GroceryList object
	GroceryList *list = Load_TXT(f_name);
	// Checks if the data loaded properly, exits if not
	if (list == nullptr) {
		return 1;
	}

	// Writes the processed data to frequency.dat
	write_to_dat(*list->getList());

	// Sets a while loop to get user input
	int option;
	while (option != 4) {
		option = menu();
		// Switch to respond to user input
		switch(option) {
			case 1:
				list->query();
				break;
			case 2:
				list->standardPrint();
				break;
			case 3:
				list->histogram();
		}
	}
	cout << "Goodbye!" << endl;
}


GroceryList* Load_TXT(string f_name) {
	ifstream inFS;
	inFS.open(f_name, ios::binary);
	if (!inFS.is_open()) {
		cout << "Could not open " << f_name << endl;
		return nullptr;
	}
	
	GroceryList *list = new GroceryList();
	string currLine;
	while (getline(inFS, currLine)) {
		if (currLine.at(currLine.size() - 1) == '\r') {
			currLine.erase(currLine.size() - 1);
		}
		list->addItem(currLine);
	}
	inFS.close();
	return list;
}

int menu() {
	cout << "MENU\n1. Search by word\n2. Print frequency of each term with numbers\n3. Print a histogram\n4. Exit" << endl;
	int userChoice = 0;
	cin.exceptions(ios::failbit);
	do {
		try {
			cout << endl << "Please choose one of the options: ";
			cin >> userChoice;
		}
		catch(exception any) {
			cout << endl << "Invalid input. Please make a choice from the menu." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	} while (userChoice > 4 || userChoice < 1);
	cout << endl;
	return userChoice;
}

void write_to_dat(vector<Item*> itemList) {
	ofstream outFile;
	outFile.open("frequency.dat");
	string outString;
	for (Item* i:itemList) {
		outString = i->getName() + ' ' + to_string(i->getCount()) + '\n';
		outFile << outString;
	}
	outFile.close();
	return;
}
