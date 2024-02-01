#include <iostream>
#include <string>

using namespace std;

void calcDenom(int pennies, int myCoins[]);

int main() {
	int pennies = 0;
	const int myCoinsSize = 6;
	int myCoins[myCoinsSize];
	string denom[myCoinsSize] = { "Dollars", "Half-Dollar", "Quarters", "Dimes", "Nickels", "Pennies" };
	cout << "Please enter number of pennies: " << endl;
	cin >> pennies;
	calcDenom(pennies, myCoins);
	for (int i = 0; i < myCoinsSize; i++) {
		(myCoins[i] > 0) ? cout << myCoins[i] << " " << denom[i] : cout << " "; // ask why it requires that second denom to have no error
		cout << endl;
	}
}

void calcDenom(int pennies, int myCoins[]) {
	int dollar = pennies / 100;
	pennies %= 100;

	int halfDollar = pennies / 50;
	pennies %= 50;

	int quarter = pennies / 25;
	pennies %= 25;

	int dime = pennies / 10;
	pennies %= 10;

	int nickel = pennies / 5;
	pennies %= 5;
	

	for (int i = 0; i < 6; i++) {
		switch (i) {
		case 0:
			myCoins[i] = dollar;
			break;
		case 1:
			myCoins[i] = halfDollar;
			break;
		case 2:
			myCoins[i] = quarter;
			break;
		case 3:
			myCoins[i] = dime;
			break;
		case 4:
			myCoins[i] = nickel;
			break;
		case 5:
			myCoins[i] = pennies;
			break;
		}
		//trying out case statement, may need to hardcode in each part of the array
	}

	

}