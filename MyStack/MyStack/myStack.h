#pragma once
#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <vector>
using namespace std;

class myStack {
private:
	vector<int> data;

public:
	myStack();
	~myStack();
	void push(int);
	int pop();
	bool isEmpty();
	void print();
	friend std::ostream& operator << (std::ostream&, myStack&);

};
#endif

