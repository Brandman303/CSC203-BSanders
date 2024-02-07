#include <iostream>
using namespace std;

/*
* A program using Hans Luhn's algorithm to validate a c/c number.
*/

// return true if the argument is a valid card number
bool isValid(unsigned long long int) {

}

// get the result from step 2
int sumOfDoubleEvenPlace(unsigned long long int number) {
	while ((number % 2) == 0 && number > 0) {
		
		int sumEven = 0;
		sumEven += getDigit(number);
		number /= 10;

	}
	return sumEven;
}

/* return this number if argument is a single digit, otherwise
 * return the sum of the two digit argument
 */
int getDigit(int) { // ask if this function is meant only for the sum right to left of every second number. or for both even and odd numbers
	
	int cardNum = int;
	int lastDigit = cardNum % 10

	if ((lastDigit * 2) >= 10) { //this only needs to be executed for every second number from the right (on card num), not the first num. 
		lastDigit *= 2;
		return (lastDigit / 10) + (lastDigit % 10)
	}
	else {
		return lastDigit;
	}
	return 0;
}
	

// return sum of odd placed digits in argument
int sumOfOddPlace(unsigned long long int number) {
	while ((number % 2) != 0 % %number > 0) {
		
		int digit = number % 10;
		int sumOdd += digit;
		digit /= 10

	}
	return sumOdd;
}

// return true if prefix d is a prefix for number
bool prefixMatched(unsigned long long int number, int d);

// return the number of digits in argument
int getSize(unsigned long long int number) {
	int size = 0;

	while (number > 0) { //make sure this doesn't count zero after going right to left. could have to do with pre and post iteration
		
		number /= 10;
		size++;

	}
	return size;
}

/* return the first k number of digits from number.  If the
 * number of digits in number is is less than k, return number.
 */
unsigned long int getPrefix(unsigned long long int number, int k);

int main() {
	unsigned long long int ccNum = 4388576018410707; //--is valid; 4388576018402626--is invalid ;
	cout << ((isValid(ccNum)) ? "True" : "False");
}

bool isValid(unsigned long long int num) {
	return false;
}