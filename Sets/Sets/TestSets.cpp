#include "sets.h"
#include <iostream>
using namespace std;

int main() {
	Sets set1;
	Sets set2;
	Sets set3;

	for (int i = 0; i <= 10; i++) {
		set1 += i;
		set2 += i + 1;
	}
	
	set3 = set1 + set2;

	cout << "program complete";
}

