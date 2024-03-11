#include "myStack.h"

//Constructor
myStack::myStack() {
	
}

//Destructor
myStack::~myStack() {

}

//Adds to the stack
void myStack::push(int num) {
	data.push_back(num);
}

//pops from stack
int myStack::pop() {
	int num;
	if (data.empty()) {
		throw out_of_range("The stack is empty");
	}
	num = data.back();
	data.pop_back();
	return num;
}

//Checks if stack is empty
bool myStack::isEmpty() {
	return data.empty();
}

//Prints what is in stack
void myStack::print() {
	for (int num : data) {
		cout << num << " ";
	}
}

//Overload <- this is so myStack can work with ostream
std::ostream& operator<<(std::ostream& os, myStack& stack) {
	for (const int& element : stack.data) {
		os << element << ' ';
	}
	return os;
}