#pragma once
#include "Vector.h"
/// <summary>
/// class of stack
/// </summary>
class Stack
{
	Vector* v;

public:
	//defult ctor
	Stack(int _size = 0, int val = 0);
	//copy ctor
	Stack(const Stack& s);

	Stack(Vector v);

	~Stack();

	//pop val from stack
	int pop();

	//push val to stack
	void push(int val);

	//check if stack empty
	bool isEmpty();

	Stack operator=(const Stack s);

	bool operator==(Stack s);

	bool operator!=(Stack s);

	bool operator>(Stack s);

	bool operator<(Stack s);

	void operator+=(Stack s);

	Stack operator+(Stack s);

	void operator+=(int num);

	void operator-=(int num);

	void operator*=(int num);

	void operator/=(int num);

};
