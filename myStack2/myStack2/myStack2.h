#pragma once
#ifndef MYSTACK2_H
#define MYSTACK2_H

#include <iostream>
#include <vector>
using namespace std;
namespace stack { //what is the nameing convention for namespace?
	template <typename T>
	class myStack2;

	template <typename T>
	class myStack2 {
	private:
		vector<T> data; 
	public:
		myStack2(); 
		~myStack2();
		void push(T d);
		T pop();
		bool isEmpty();
		void print(ostream& os) const;
		friend std::ostream& operator << (std::ostream&, myStack2<T>&); 
		T get() const;
		void set(T& d);
	};

	template <typename T>
	myStack2<T>::myStack2()
		: data() {
	}

	template <typename T>
	myStack2<T>::~myStack2() {
	}

	template <typename T>
	void myStack2<T>::push(T d) {
		data.push_back(d);
	}

	template<typename T>
	T myStack2<T>::pop() {
		if (!data.empty()) {
			T d = data.back();
			data.pop_back();
			return d;
		}
		throw ("Unable to pop. Stack is empty");
	}

	template <typename T>
	bool myStack2<T>::isEmpty() {
		return data.empty();
	}
	template <typename T>
	T myStack2<T>::get() const {
		return data;
	}

	template <typename T>
	void myStack2<T>::set(T& d) {
		data = d;
	}

	template <typename T>
	void myStack2<T>::print(ostream& os) const{ //this Will write to file
		for (auto it = data.rbegin(); it != data.rend(); ++it) {
			os << *it << endl;
		}
	}
	template <typename T>
	std::ostream& operator<<(std::ostream& os, const myStack2<T>& stack) {
		for (const T& elem : stack) {
			os << elem << " ";
		}
		return os;
	}
}
#endif
