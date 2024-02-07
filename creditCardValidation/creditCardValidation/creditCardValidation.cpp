#include <iostream>
using namespace std;

/*
* A program using Hans Luhn's algorithm to validate a c/c number.
*/

// return true if the argument is a valid card number
bool isValid(unsigned long long int number);


// get the result from step 2
int sumOfDoubleEvenPlace(unsigned long long int number);


/* return this number if argument is a single digit, otherwise
 * return the sum of the two digit argument
 */
int getDigit(int num);


// return sum of odd placed digits in argument
int sumOfOddPlace(unsigned long long int number);


// return true if prefix d is a prefix for number
bool prefixMatched(unsigned long long int number, int d);

// return the number of digits in argument
int getSize(unsigned long long int number);


/* return the first k number of digits from number.  If the
 * number of digits in number is is less than k, return number.
 */
unsigned long int getPrefix(unsigned long long int number, int k);

int main() {
	unsigned long long int ccNum = 4388576018410707; //--is valid; 4388576018402626--is invalid ;
	cout << ((isValid(ccNum)) ? "True" : "False");
}

bool isValid(unsigned long long int number) {
	int size;
	int theSums;
	int sumEven = sumOfDoubleEvenPlace(number); // corrected
	int sumOdd = sumOfOddPlace(number); //need2fix


	size = getSize(number);
	theSums = sumEven + sumOdd;
	
	return (size >= 13 && size <= 16 && (theSums % 10) == 0) ? true : false;
}
int sumOfDoubleEvenPlace(unsigned long long int number) {
	int sumEven = 0;
	int lastDigit;
	bool evenDigit = false;

	while (number > 0) {
		lastDigit = number % 10;
		if (evenDigit) {
			int doubledDigit = lastDigit * 2;
			sumEven += getDigit(doubledDigit);
		}
		evenDigit = !evenDigit;
		number /= 10;
	}
	return sumEven;
}
int getDigit(int num) { // ask if this function is meant only for the sum right to left of every second number. or for both even and odd number
	return (num >= 10) ? ((num / 10) + (num % 10)) : num;
}
int sumOfOddPlace(unsigned long long int number) {
	int lastDigit;
	int sumOdd = 0;
	bool oddDigit = true;
	while (number > 0) {
		lastDigit = number % 10;
		if (oddDigit) {
			sumOdd += lastDigit;
		}
		oddDigit = !oddDigit;
		number /= 10;

	}
	return sumOdd;
}
int getSize(unsigned long long int number) {
	int size;
	size = 0;

	while (number > 0) { //make sure this doesn't count zero after going right to left. could have to do with pre and post iteration

		number /= 10;
		size++;

	}
	return size;
}
