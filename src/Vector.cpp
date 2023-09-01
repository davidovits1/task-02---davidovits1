#include <iostream>
#include "Vector.h"

void Vector::set(Vector v)
{
	capacity = v.capacity;
	size = v.size;
	for (int i = 0; i < size; i++)
	{
		vec[i] = v.vec[i];
	}
}

int Vector::insertCapacity(int capa, int n)
{
	if (capa == 0)
	{
		capa += 1;
	}
	while (capa < n)
	{
		if (capa < FIRSTMAX)
		{
			capa = capa * 2;
		}
		else
		{
			capa = int(capa * 1.5);
		}
	}
	return capa;
}

void Vector::set(int size, int* v)
{
	for (int i = 0; i < size; i++)
	{
		vec[i] = v[i];
	}
}

int* Vector::copy(int* temp)
{
	for (int i = 0; i < size; i++)
	{
		temp[i] = vec[i];
	}
	return temp;
}



Vector::Vector(int size, int value)
{
	if (size != 0)
	{
		vec = new int[size];
		this->capacity = size;
		this->size = 1;
		vec[0] = value;
	}
	else
	{
		vec = nullptr;
		capacity = this->size = 0;
	}
}

Vector::Vector(const Vector& v)
{
	vec = new int[v.capacity];
	capacity = v.capacity;
	size = v.size;
	for (int i = 0; i < size; i++)
	{
		vec[i] = v.vec[i];
	}

}

Vector::Vector(int size, int* arr)
{
	capacity = size;
	vec = new int[capacity];
	this->size = size;
	set(size, arr);
}

Vector::~Vector()
{
	delete[] vec;
}

Vector Vector::operator=(const Vector& v)
{
	if (!empty())
	{
		delete[] vec;
	}
	vec = new int[v.capacity];
	set(v);

	return *this;
}

int* Vector::data()
{
	return vec;
}

bool Vector::empty() const
{
	return size == 0;
}

int Vector::Size() const
{
	return size;
}

int Vector::Capacity() const
{
	return capacity;
}

void Vector::clear()
{
	if (!empty())
	{
		delete[] vec;
		size = 0;
		if (capacity != 0)
		{
			vec = new int[capacity];
		}
	}
}

void Vector::resize(int n, int val)
{
	if (n <= size)
	{
		int i = size - n;
		for (i; i < size; i++)
		{
			vec[i] = 0;
		}
		size = size - n;
	}
	else
	{
		if (n < capacity)
		{
			int i = size;
			for (i; i < n; i++)
			{
				vec[i] = val;
			}
			size = n;
		}
		else
		{
			capacity = insertCapacity(capacity, n);

			int* temp = new int[capacity];
			temp = copy(temp);
			for (int i = size; i < n; i++)
			{
				temp[i] = val;
			}
			size = n;
			delete[] vec;
			vec = temp;
		}

	}

}

void Vector::swap(const Vector& v)
{
	*this = v;
}

void Vector::push_back(const int val)
{
	if (val != 0)
	{
		if (size < capacity)
		{
			vec[size] = val;
			size += 1;
		}
		else
		{
			capacity = insertCapacity(capacity, capacity + 1);
			int* temp = new int[capacity];
			size += 1;
			for (int i = 0; i < size - 1; i++)
			{
				temp[i] = vec[i];
			}
			temp[size - 1] = val;
			delete[] vec;
			vec = temp;
		}
	}

}

//int& Vector::operator=(int& v)
//{
//	size += 1;
//	
//	return v;
//}


void Vector::pop_back()
{
	if (!empty())
	{
		vec[size - 1] = 0;
		size -= 1;
	}
}

int& Vector::operator[](int i)
{
	if (0 <= i && i < size)
	{
		return vec[i];
	}
	else
	{
		std::exception e("index out of range\n");
		throw e;
	}
}

bool Vector::operator==(const Vector& v)
{
	if (capacity == v.capacity && size == v.capacity)
	{
		for (int i = 0; i < size; i++)
		{
			if (vec[i] != v.vec[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

Vector Vector::operator+(Vector v)
{
	Vector v1(*this);
	v1 += v;
	return v1;
}

void Vector::operator+=(Vector v)
{
	int newSize = size + v.size;
	if (newSize < capacity)
	{
		int j = 0;
		for (int i = size; i < newSize; i++)
		{
			vec[i] = v[j];
			j++;
		}
		
	}
	else
	{
		int newCapacity = insertCapacity(capacity, newSize);
		int* temp = new int[newCapacity];
		temp = copy(temp);
		int j = 0;
		for (int i = size; i < newSize; i++)
		{
			temp[i] = v[j];
			j++;
		}
		
		delete[] vec;
		vec = temp;
		capacity = newCapacity;
	}
	size = newSize;
}

void Vector::operator+=(int num)
{
	for (int i = 0; i < size; i++)
	{
		vec[i] += num;
	}
}

void Vector::operator-=(int num)
{
	for (int i = 0; i < size; i++)
	{
		vec[i] -= num;
	}
}

void Vector::operator*=(int num)
{
	for (int i = 0; i < size; i++)
	{
		vec[i] *= num;
	}
}

void Vector::operator/=(int num)
{
	for (int i = 0; i < size; i++)
	{
		vec[i] /= num;
	}
}

void Vector::insert(int index, int val)
{
	if (index == size)
	{
		push_back(val);
	}
	else
	{
		if (index < size)
		{
			if (size < capacity) // insert to vec
			{
				int prev = vec[index];
				vec[index] = val;
				size += 1;
				int i = index + 1;
				for (i; i < size; i++)
				{
					int t = vec[i];
					vec[i] = prev;
					prev = t;
				}
			}

			else // size == capacity
			{
				capacity = insertCapacity(capacity, capacity + 1);
				int* temp = new int[capacity];
				temp = copy(temp);
				int prev = temp[index];
				temp[index] = val;
				size += 1;
				int i = index + 1;
				for (i; i < size; i++)
				{
					int t = vec[i];
					vec[i] = prev;
					prev = t;
				}
				delete[] vec;
				vec = temp;
			}
		}
	}
}

void Vector::erase(int index)
{
	if (index < size)
	{
		int next = vec[size - 1];
		for (int i = size - 2; i >= index; i--)
		{
			int temp = vec[i];
			vec[i] = next;
			next = temp;
		}
		size -= 1;
	}
}



