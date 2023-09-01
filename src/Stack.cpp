#include "Stack.h"

Stack::Stack(int size, int val)
{
	v = new Vector(size, val);
}

Stack::Stack(const Stack& s)
{
	v = new Vector(*s.v);
}

Stack::Stack(Vector v)
{
	this->v = new Vector(v);
}

Stack::~Stack()
{
	delete v;
}

Stack Stack::operator=(const Stack s)
{
	*v = *s.v;
	return *this;
}


int Stack::pop()
{
	int i = v->Size() - 1;
	int val = v->data()[i];
	v->pop_back();
	return val;
}

void Stack::push(int val)
{
	v->push_back(val);
}

bool Stack::isEmpty()
{
	return v->empty();
}



bool Stack::operator==(Stack s)
{
	return v == s.v;
}

bool Stack::operator!=(Stack s)
{
	return !(*this == s);
}

bool Stack::operator>(Stack s)
{
	return v->Capacity() > s.v->Capacity();
}

bool Stack::operator<(Stack s)
{
	return v->Capacity() < s.v->Capacity();
}

void Stack::operator+=(Stack s)
{
	*v += *s.v;
}

Stack Stack::operator+(Stack s)
{
	Stack s1(*this);
	s1 += s;
	return s1;

}


void Stack::operator+=(int num)
{
	*v += num;
}

void Stack::operator-=(int num)
{
	*v -= num;
}

void Stack::operator*=(int num)
{
	*v *= num;
}

void Stack::operator/=(int num)
{
	*v /= num;
}

