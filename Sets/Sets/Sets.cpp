#include "Sets.h"

Sets::Sets() {

}
Sets::~Sets() {

}

void Sets::operator+=(const int& right) {
	set.push_back(right);
}
void Sets::operator-=(const int& right) { // was originally left, check later
	//I think this takes a specific integer and searches the set then removes that integer,
	// rather than just removing whatever is on top of the stack
	set.pop_back();
}
Sets& Sets::operator=(const Sets& right) {
	if (this == &right) return *this;
	set = right.set;
	return *this;
}
//- and + don't need friend in front here?
Sets operator*(const Sets& left, const Sets& right) {
	Sets result;
	for (int element : left.set) {
		for (int oElement : right.set) {
			if (element == oElement) {
				result += element;
				break;
			}
		}
	}
	return result;
}
Sets operator-(const Sets& left, const Sets& right) {
	Sets difference;
	bool match;
	for (int element : left.set) {
		match = false;
		for (int oElement : right.set) {
			if (element == oElement) {
				match = true;
				break;
			}
		}
		if (match != true) {
			difference += element;
		}
	}
	return difference;
}
Sets operator+(const Sets& left, const Sets& right) {
	Sets sum;
	bool match;
	for (int elem : left.set) {
		sum += elem;
	}
	for (int element : right.set) {
		match = false;

		for (int oElement : sum.set) {
			if (element == oElement) {
				match = true;
				break;
			}
		}
		if (!match) {
			sum += element; 
		}
	}
	return sum;
}

void Sets::print() const {
	for (int element : set) {
		cout << element << " ";
	}
	cout << endl;
}
