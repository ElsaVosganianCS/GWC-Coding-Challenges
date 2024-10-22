// Elsa Vosganian
// GWC LAPC Challenge #2: this program receives a Roman numeral and converts it to an integer
// October 22nd 2024

#include <iostream>
#include <string>

using namespace std;

int main() {
	// declares
	string userRoman = "";
	char menuChoice = 'y';

	// menu
	while (menuChoice != 'n' && menuChoice != 'N') {
		// initialize counter for Roman numeral values
		int userInt = 0;
		bool validInput = true;

		cout <<"-.* Roman Numeral Calculator *.-\n"
			 << "-------------------------------------" << endl;
		cout << "Valid Characters: I, V, X, L, C, D, M" << endl;
		
		// receive roman numeral from user
		cout << "Enter your Roman numeral: ";
		cin >> userRoman;
		cout << endl;

		// calculate integer from roman numeral by going through the string's elements in reverse
		for (int i = userRoman.length() - 1; i >= 0; --i) {
			switch (userRoman[i]) {
				case 'M':
					// M = 1000
					userInt += 1000;

					if (i != 0) {
						//if C is in front of M, CM = 900
						if (userRoman[i - 1] == 'C') {
							userInt -= 100;
							--i;
						}
					}

					break;
				case 'D':
					// D = 500
					userInt += 500;

					if (i != 0) {
						//if C is in front of D, CD = 400
						if (userRoman[i - 1] == 'C') {
							userInt -= 100;
							--i;
						}
					}

					break;
				case 'C':
					// C = 100
					userInt += 100;

					if (i != 0) {
						//if X is in front of C, XC = 90
						if (userRoman[i - 1] == 'X') {
							userInt -= 10;
							--i;
						}
					}

					break;
				case 'L':
					// L = 50
					userInt += 50;

					if (i != 0) {
						//if X is in front of L, XL = 40
						if (userRoman[i - 1] == 'X') {
							userInt -= 10;
							--i;
						}
					}

					break;
				case 'X':
					// X = 10
					userInt += 10;

					if (i != 0) {
						//if I is in front of X, IX = 9
						if (userRoman[i - 1] == 'I') {
							userInt -= 1;
							--i;
						}
					}

					break;
				case 'V':
					// V = 5
					userInt += 5;
					
					if (i != 0) {
						//if I is in front of V, IV = 4
						if (userRoman[i - 1] == 'I') {
							userInt -= 1;
							--i;
						}
					}

					break;
				case 'I':
					// I = 1
					userInt += 1;
					break;
				default:
					// validate input: show error to user when invalid character is detected
					cout << " * ERROR: Invalid character \'" << userRoman[i] << "\' at index " << i << endl;
					validInput = false;
					break;
			}
		}

		// if invalid input, set userInt to -1
		if (validInput == false) {
			cout << " * ERROR: One or more invalid characters were\n" 
				 << "   detected; value has been set to -1\n" << endl;
			userInt = -1;
		}
		
		// output calculated integer
		cout << "Your Roman numeral is: \t[" << userRoman << "]" << endl;
		cout << "The value is: \t\t[" << userInt << "]" << endl;

		// ask user if they want to continue
		cout << "\nWould you like to input another number? (Y/N): ";
		cin >> menuChoice;

		cout << endl;
	}

	cout << "Ending program..." << endl;
}
