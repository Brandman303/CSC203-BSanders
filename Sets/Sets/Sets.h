#pragma once
#ifndef SETS_H
#define SETS_H

#include <iostream>
#include <vector>
using namespace std;

class Sets {
private:
	vector<int> set;

public:
	Sets();
	~Sets();

	void operator+=(const int& right);
	void operator-=(const int& right); //was orignally left, check later
	Sets& operator=(const Sets& right);

	friend Sets& operator*(const Sets& left, const Sets& right);
	friend Sets& operator-(const Sets& left, const Sets& right);
	friend Sets& operator+(const Sets& left, const Sets& right);


	void print() const;

};

#endif