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
	unsigned long long int ccNum;
	bool enterNum = true;
	string yesNo;
	do {//4388576018410707--is valid; 4388576018402626--is invalid ;
		cout << "Please enter your credit number without spaces or dashes: " << endl;
		cin >> ccNum;
		cout << endl << (isValid(ccNum) ? "True" : "False") << endl;
		cout << "Would you like to enter another credit card number? y/n" << endl;
		cin >> yesNo;
		if (yesNo != "y") {
			enterNum = false;
			cout << endl << "Goodbye" << endl;
		}
	} while (enterNum);
	
}

bool isValid(unsigned long long int number) {
	int size = getSize(number);
	int totSum;
	int prefix = getPrefix(number, 2);
	totSum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
	if (prefix == 37 || prefix == 4 || prefix == 5 || prefix == 6) {
		return (size >= 13 && size <= 16 && (totSum % 10) == 0) ? true : false;
	}
	else {
		return false;
	}
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
int getDigit(int num) { 
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

	while (number > 0) { 
		number /= 10;
		size++;

	}
	return size;
}
unsigned long int getPrefix(unsigned long long int number, int k) {
	int size;
	if (number < k) {
		return number;
	}
	else {
		size = getSize(number);
		for (int i = 0; i < (size - k); i++) {
			number /= 10;
		}
		if (number == 37) {
			return number;
		}
		else {
			return number /= 10;
		}
	}
}