#include "sets.h"
#include <iostream>
using namespace std;

int main() {
	Sets set1;
	Sets set2;
	Sets set3;

	for (int i = 0; i <= 10; i++) {
		set1 += i;
		set2 += i + 5;
	}
	
	cout << "Before union: " << endl;
	set1.print();
	set2.print();
	set3 = set1 + set2;
	cout << "After union: " << endl;
	set3.print();
	cout << endl;

	cout << "Before difference: " << endl;
	set1.print();
	set2.print();
	set3 = set1 - set2;
	cout << "After difference: " << endl;
	set3.print();
	cout << endl;

	cout << "Before intersection: " << endl;
	set1.print();
	set2.print();
	set3 = set1 * set2;
	cout << "After intersection: " << endl;
	set3.print();


}


