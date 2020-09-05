/*
Program Header:

@Author William A Becker
@Version 1.1

*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

//Constants
int selection;

//Prototypes
void switchMenu();
void factorAndDisplay();
void factorAndSave();
void factorAndVector();

int main(int argc, char* argv[]) {
	do {
		switchMenu();
		switch (selection) {
		case 1: {
			factorAndDisplay();
		} break;
		case 2: {
			factorAndSave();
		} break;
		case 3: {
			factorAndVector();
		} break;
		case 0: {
		} break;
		default: {
			cout << "ERROR!!! You have not made a valid selection!\n\n";
		}
		}
	} while (selection != 0);
	return 0;
}

void switchMenu() {
	cout << "Please make a selection:\n\n";

	cout << "1) Factor and display.\n";
	cout << "2) Factor and save to file\n";
	cout << "3) Factor and save to Vector\n\n";

	cout << "0) Exit\n\n";

	cout << "Selection: ";

	cin >> selection;

	cout << "\n";

	// Input check and scrub
	if (selection < 0 || selection > 3 || cin.fail()) {
		selection = 99;
		cin.clear();
	}
}

void factorAndDisplay() {
	int numbToFactor;
	do {
		cout << "Please enter an integer to factor: ";

		cin >> numbToFactor;
		//input check and scrub
		if (numbToFactor < 0 || cin.fail()) {
			cout << "ERROR!!! You have not entered an appropriate interger!\n\n";
			cin.clear();
			break;
		}
		cout << "\n";

		if (numbToFactor == 0) {
			cout << "All real Numbers are a factor of 0!\n\n";
		}
		else {
			//This is the actual part that does all the factoring
			for (int i = 1; i <= floor(sqrt(numbToFactor)); i++) {
				int j = numbToFactor / i;
				if (numbToFactor % i == 0) {
					cout << i << " , " << j << "\n";
				}
			}
			cout << "\nPress enter to continue.\n\n";
			cin.clear();
			cin.ignore();
			cin.get();
			return;
		}
	} while (true);
}

void factorAndSave() {
	ofstream fout;
	string fileName;
	int numbToFactor;
	do {
		cout << "What would you like to save the results as: ";
		cin >> fileName;
		fileName += ".txt";
		fout.open(fileName);
		while (fout.is_open()) {
			cout << "Please enter an integer to factor: ";

			cin >> numbToFactor;
			//input check and scrub
			if (numbToFactor < 0 || cin.fail()) {
				cout << "ERROR!!! You have not entered an appropriate interger!\n\n";
				cin.clear();
				break;
			}
			cout << "\n";
			//This is needed to prevent an endless loop.
			if (numbToFactor == 0) {
				cout << "All real Numbers are a factor of 0!\n\n";
			}
			else {
				//This is the actual part that does all the factoring
				for (int i = 1; i <= floor(sqrt(numbToFactor)); i++) {
					int j = numbToFactor / i;
					if (numbToFactor % i == 0) {
						fout << i << " , " << j << "\n";
					}
				}
				//Clear, save, and return to menu
				cout << "\nPress enter to continue.\n\n";
				cin.clear();
				cin.ignore();
				cin.get();
				fout.close();
				return;
			}
		}
	} while (true);
}
//This function is currently pointless but may be used in another program. Output is identical to factorAndDisplay
void factorAndVector() {
	int numbToFactor;

	do {
		cout << "Please enter an integer to factor: ";

		cin >> numbToFactor;
		//input check and scrub
		if (numbToFactor < 0 || cin.fail()) {
			cout << "ERROR!!! You have not entered an appropriate interger!\n\n";
			cin.clear();
			break;
		}
		cout << "\n";

		vector<int> factors1stPair;
		vector<int> factors2ndPair;

		int a = 0;
		if (numbToFactor == 0) {
			cout << "All real Numbers are a factor of 0!\n\n";
		}
		else {
			//This is the actual part that does all the factoring
			for (int i = 1; i <= floor(sqrt(numbToFactor)); i++) {
				int j = numbToFactor / i;
				if (numbToFactor % i == 0) {
					factors1stPair.push_back(i);
					factors2ndPair.push_back(j);
				}
			}
			//Display the array
			for (int i = 0; i < a;i++) {
				cout << factors1stPair[i] << " , " << factors2ndPair[i] << "\n";
			}
			//Clear and return to menu
			cout << "\nPress enter to continue.\n\n";
			cin.clear();
			cin.ignore();
			cin.get();
			return;
		}
	} while (true);
}