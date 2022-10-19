#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>

using namespace std;

int main() {
	ifstream inFS;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int WHITE = 7;
	int fileChoice;
	int fileContent = 0;
	int xAxisVal = 10;
	int Axis = 1;
	int numX = 0;
	int invalidChar = 0;
	int firstSmall = 200;
	int secondSmall = 200;
	int thirdSmall = 200;
	int firstLarge = -100;
	int secondLarge = -100;
	int thirdLarge = -100;

	do {
		system("cls");
		cout << "Select file to proceed\n";
		cout << "1. mixed.txt\n";
		cout << "2. valid.txt\n";
		cout << "3. three.txt\n";
		cout << "4. missing.txt\n\n";
		cout << "Choice: ";
		cin >> fileChoice;
		cout << "\n";

	} while (fileChoice > 4 || fileChoice < 1);

	switch (fileChoice) {

	case 1:
		inFS.open("mixed.txt");
		if (inFS.is_open()) {
			cout << "Bar graph for data contained in mixed.txt\n\n";
			break;
		}
	case 2:
		inFS.open("valid.txt");
		if (inFS.is_open()) {
			cout << "Bar graph for data contained in valid.txt\n\n";
			break;
		}
	case 3:
		inFS.open("three.txt");
		if (inFS.is_open()) {
			cout << "Bar graph for data contained in three.txt\n\n";
			break;
		}
	case 4:
		cout << "ERROR: Data file not found.";
		return 1;
	}

	while (inFS >> fileContent) {
		if (fileContent == 9999) {
			break;
		}
		SetConsoleTextAttribute(hConsole, WHITE);
		cout << setfill(' ') << setw(2) << Axis;
		cout << " | ";
		if (fileContent > 112) {
			SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
			++invalidChar;
		}
		if (fileContent < 0) {
			SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
			++invalidChar;
		}

		for (numX = 1; numX <= fabs(fileContent); ++numX) {
			cout << "X";
			if (numX > 112) {
				break;
			}
		}
		if (fileContent > firstLarge) {
			thirdLarge = secondLarge;
			secondLarge = firstLarge;
			firstLarge = fileContent;
		}
		else if (fileContent > secondLarge) {
			thirdLarge = secondLarge;
			secondLarge = fileContent;
		}
		else if (fileContent > thirdLarge) {
			thirdLarge = fileContent;
		}

		if (fileContent < firstSmall) {
			thirdSmall = secondSmall;
			secondSmall = firstSmall;
			firstSmall = fileContent;
		}
		else if (fileContent < secondSmall) {
			thirdSmall = secondSmall;
			secondSmall = fileContent;
		}
		else if (fileContent < thirdSmall) {
			thirdSmall = fileContent;
		}

		Axis += 1;
	}
	for (Axis = 0; Axis < 113; ++Axis) {
		cout << "-";
	}
	cout << "\n";
	for (Axis = 0; Axis <= 10; ++Axis) {
		cout << "        " << xAxisVal;
		xAxisVal += 10;
	}

	cout << "SMALLEST\n" << "The smallest value: " << firstSmall << "\n";
	cout << "The second smallest value: " << secondSmall << "\n";
	cout << "The third smallest value: " << thirdSmall << "\n";
	cout << "LARGEST\n" << "The largest value: " << firstLarge << "\n";
	cout << "The second largest value: " << secondLarge << "\n";
	cout << "The third largest value: " << thirdLarge << "\n";
	cout << "There were " << invalidChar << " invalid characters.\n";

	inFS.close();

	return 0;


}