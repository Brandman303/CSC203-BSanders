#include <iostream>
#include <fstream>
#include <string>
#include <sstream> //provides functionality, such as formatting strings as an input stream. Allowing for easier parsing
#include "myStack.h"

//function to evaluate rpn
int evaluate(const string& rpn, myStack& stack);

int main() {
	string line;

	ifstream file("rpnArithmetic.txt");
	if (!file) {
		cerr << "Failed to open rpnArithmetic.txt";
		return 1;
	}

	while (getline(file, line)) {
		myStack stack;
		try {
			int result = evaluate(line, stack);
			cout << line << " = " << result << endl;
		}
		catch (const exception& e) {
			cout << "Could not evaluate rpn expression " << line << endl;
		}
	}

	file.close();
	return 0;
}

int evaluate(const string& rpn, myStack& stack) {
	stringstream tokens(rpn);
	string token;
	// while the parsed stream of char tokens has a char token continue the encapsulated code.
	while (tokens >> token) {
		//checks if token is a positive or negative digit
		if (isdigit(token[0]) || (token.length() > 1 && token[0] == '-')) {
			stack.push(stoi(token));
		}
		//else it is not a digit and an operator being read.
		else { // remember LIFO
			int operand2 = stack.pop();
			int operand1 = stack.pop();
			switch(token[0]) {
				case '+': 
					stack.push(operand1 + operand2);
					break;
				case '-': 
					stack.push(operand1 - operand2);
					break;
				case '*': 
					stack.push(operand1 * operand2);
					break;
				case '/':
					if (operand2 == 0) {
						throw runtime_error("Cannot divide by 0");
					}
					stack.push(operand1 / operand2);
					break;
				default: 
					throw runtime_error("Not a vaild operator " + token);
			}
		}
	}
	return stack.pop();
}