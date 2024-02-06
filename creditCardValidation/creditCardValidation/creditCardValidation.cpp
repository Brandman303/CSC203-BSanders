#include <iostream>
using namespace std;

/*
* A program using Hans Luhn's algorithm to validate a c/c number.
*/

// return true if the argument is a valid card number
bool isValid(unsigned long long int);

// get the result from step 2
int sumOfDoubleEvenPlace(unsigned long long int number);

/* return this number if argument is a single digit, otherwise
 * return the sum of the two digit argument
 */
int getDigit(int);

// return sum of odd placed digits in argument
int sumOfOddPlace(unsigned long long int);

// return true if prefix d is a prefix for number
bool prefixMatched(unsigned long long int number, int d);

// return the number of digits in argument
int getSize(unsigned long long int);

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