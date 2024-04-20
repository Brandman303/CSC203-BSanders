#include <iostream>
#include <fstream>
#include <string>
#include <sstream> //provides functionality, such as formatting strings as an input stream. Allowing for easier parsing
#include "myStack2.h"
using namespace std;
using namespace stack;
//function to evaluate rpn
int evaluate(const string& rpn, myStack2<int>& stack);

int main() {
	myStack2<int> integerStack;
	myStack2<float> floatStack;
	myStack2<string> stringStack;

	integerStack.push(1);
	integerStack.push(2);
	integerStack.push(3);

	floatStack.push(1.1f);
	floatStack.push(2.2f);
	floatStack.push(3.3f);
	
	stringStack.push("one");
	stringStack.push("two");
	stringStack.push("three");

	ofstream outFile("myStack2.txt");
	if (!outFile) {
		cerr << "Failed to open a write-to-file" << endl;
		return 1;
	}

	outFile << "Integers: " << endl;
	integerStack.print(outFile);
	outFile << "Floats: " << endl;
	floatStack.print(outFile);
	outFile << "strings: " << endl;
	stringStack.print(outFile);

	outFile.close();

	ifstream file("rpnArithmetic.txt");
	if (!file) {
		cerr << "Failed to open rpnArithmetic.txt";
		return 1;
	}
	string line;
	while (getline(file, line)) {
		myStack2<int> stack;
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

int evaluate(const string& rpn, myStack2<int>& stack) {
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
			switch (token[0]) {
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