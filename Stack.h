#pragma once
#include <list>
#include <iostream>
using namespace std;

class Stack
{
private:
	list<int> lst;

public:
	Stack(){}
	void makeEmpty();
	bool isEmpty() const;

	void push(int bit);
	int pop();
	void print();

};

