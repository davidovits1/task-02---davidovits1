#include <iostream>
#include "Stack.h"
using std::cout;
using std::endl;


void print(Vector v)
{
	for (int i = 0; i < v.Size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void print(Stack s)
{
	while (!s.isEmpty())
	{
		cout << s.pop() << " ";
	}
	cout << endl;
}
int main()
{
	
	int* v = new int[10]{ 1,2,3,4,5,6,7,8,9,10 };
	Vector v1(10, v), v2(5, 30), v3;
	cout << "v1: ";
	print(v1);
	cout << "v2: ";
	print(v2);
	cout << "v3: ";
	print(v3);

	v3.push_back(3);
	v3.push_back(4);
	v2.swap(v1);
	cout << "v2 after swap: ";
	print(v2);

	v1.pop_back();
	v1.resize(5);
	cout << "v1 after pop back and resize: ";
	print(v1);
	v1.resize(8, 100);
	cout << "v1: ";
	print(v1);

	v1.insert(6, 90);
	cout << "v1: after insert ";
	print(v1);

	cout << "v3 after push back: ";
	print(v3);

	Vector v4 = v3;
	cout << "v4: ";
	print(v4);

	v4 += v2;
	Vector v5 = v1 + v4;
	cout << "v4 += v2: ";
	print(v4);
	cout << "v5 = v1 + v4: ";
	print(v5);

	cout << endl << endl;

	Stack s1(10, 1), s2(v5), s3;
	cout << "s1: ";
	print(s1);
	cout << "s2: ";
	print(s2);
	cout << "s3 ";
	print(s3);

	s2 += s1;
	cout << "s2 += s1: ";
	print(s2);

	s3 = s2 + s1;
	cout << "s3 = s2 + s1 ";
	print(s3);

	s2 /= 2;
	cout << "s2 /= s1: ";
	print(s2);

	s2 += 6;
	cout << "s2 + 6: ";
	print(s2);

	s1.push(15);
	cout << "s1 push 15: ";
	print(s1);

	s1.pop();
	cout << "s1 pop 15: ";
	print(s1);

}