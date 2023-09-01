#include <iostream>
#include "Vector.h"

Vector::Vector(Vector&& other)
	: _vec(nullptr), _capacity(0), _size(0)
{
	// Move the resources from 'other' to this object
	swap(other);
}

Vector& Vector::operator=(Vector&& other)
{
	if (this != &other)
	{
		// Release the current resources
		delete[] _vec;

		// Move the resources from 'other' to this object
		_vec = other._vec;
		_capacity = other._capacity;
		_size = other._size;

		// Reset 'other' to a valid but empty state
		other._vec = nullptr;
		other._capacity = 0;
		other._size = 0;
	}
	return *this;
}
void Vector::set(Vector v)
{
	_capacity = v._capacity;
	_size = v._size;
	for (int i = 0; i < _size; i++)
	{
		_vec[i] = v._vec[i];
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

void Vector::set(int _size, int* v)
{
	for (int i = 0; i < _size; i++)
	{
		_vec[i] = v[i];
	}
}

int* Vector::copy(int* temp)
{
	for (int i = 0; i < _size; i++)
	{
		temp[i] = _vec[i];
	}
	return temp;
}



Vector::Vector(int size, int value)
{
	if (size != 0)
	{
		_vec = new int[size];
		this->_capacity = size;
		this->_size = size;
		for (int i = 0; i < size; i++)
		{
			_vec[i] = value;
		}
	}
	else
	{
		_vec = nullptr;
		_capacity = this->_size = 0;
	}
}


Vector::Vector(const Vector& v)
{
	_vec = new int[v._capacity];
	_capacity = v._capacity;
	_size = v._size;
	for (int i = 0; i < _size; i++)
	{
		_vec[i] = v._vec[i];
	}

}

Vector::Vector(int _size, int* arr)
{
	_capacity = _size;
	_vec = new int[_capacity];
	this->_size = _size;
	set(_size, arr);
}

Vector::~Vector()
{
	delete[] _vec;
}

Vector Vector::operator=(const Vector& v)
{
	if (!empty())
	{
		delete[] _vec;
	}
	_vec = new int[v._capacity];
	set(v);

	return *this;
}

int* Vector::data()
{
	return _vec;
}

bool Vector::empty() const
{
	return _size == 0;
}

int Vector::Size() const
{
	return _size;
}

int Vector::Capacity() const
{
	return _capacity;
}

void Vector::clear()
{
	if (!empty())
	{
		delete[] _vec;
		_size = 0;
		if (_capacity != 0)
		{
			_vec = new int[_capacity];
		}
	}
}

void Vector::resize(int n, int val)
{
	if (n <= _size)
	{
		int i = _size - n;
		for (i; i < _size; i++)
		{
			_vec[i] = 0;
		}
		_size = _size - n;
	}
	else
	{
		if (n < _capacity)
		{
			int i = _size;
			for (i; i < n; i++)
			{
				_vec[i] = val;
			}
			_size = n;
		}
		else
		{
			_capacity = insertCapacity(_capacity, n);

			int* temp = new int[_capacity];
			temp = copy(temp);
			for (int i = _size; i < n; i++)
			{
				temp[i] = val;
			}
			_size = n;
			delete[] _vec;
			_vec = temp;
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
		if (_size < _capacity)
		{
			_vec[_size] = val;
			_size += 1;
		}
		else
		{
			_capacity = insertCapacity(_capacity, _capacity + 1);
			int* temp = new int[_capacity];
			_size += 1;
			for (int i = 0; i < _size - 1; i++)
			{
				temp[i] = _vec[i];
			}
			temp[_size - 1] = val;
			delete[] _vec;
			_vec = temp;
		}
	}

}


void Vector::pop_back()
{
	if (!empty())
	{
		_vec[_size - 1] = 0;
		_size -= 1;
	}
}

int& Vector::operator[](int i)
{
	if (0 <= i && i < _size)
	{
		return _vec[i];
	}
	else
	{
		std::exception e("index out of range\n");
		throw e;
	}
}

bool Vector::operator==(const Vector& v) const
{
	if (_size == v._size)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_vec[i] != v._vec[i])
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
	int newSize = _size + v._size;
	if (newSize < _capacity)
	{
		int j = 0;
		for (int i = _size; i < newSize; i++)
		{
			_vec[i] = v[j];
			j++;
		}
		
	}
	else
	{
		int newCapacity = insertCapacity(_capacity, newSize);
		int* temp = new int[newCapacity];
		temp = copy(temp);
		int j = 0;
		for (int i = _size; i < newSize; i++)
		{
			temp[i] = v[j];
			j++;
		}
		
		delete[] _vec;
		_vec = temp;
		_capacity = newCapacity;
	}
	_size = newSize;
}

void Vector::operator+=(int num)
{
	for (int i = 0; i < _size; i++)
	{
		_vec[i] += num;
	}
}

void Vector::operator-=(int num)
{
	for (int i = 0; i < _size; i++)
	{
		_vec[i] -= num;
	}
}

void Vector::operator*=(int num)
{
	for (int i = 0; i < _size; i++)
	{
		_vec[i] *= num;
	}
}

void Vector::operator/=(int num)
{
	for (int i = 0; i < _size; i++)
	{
		_vec[i] /= num;
	}
}

void Vector::insert(int index, int val)
{
	if (index == _size)
	{
		push_back(val);
	}
	else
	{
		if (index < _size)
		{
			if (_size < _capacity) // insert to vec
			{
				int prev = _vec[index];
				_vec[index] = val;
				_size += 1;
				int i = index + 1;
				for (i; i < _size; i++)
				{
					int t = _vec[i];
					_vec[i] = prev;
					prev = t;
				}
			}

			else // size == capacity
			{
				_capacity = insertCapacity(_capacity, _capacity + 1);
				int* temp = new int[_capacity];
				temp = copy(temp);
				int prev = temp[index];
				temp[index] = val;
				_size += 1;
				int i = index + 1;
				for (i; i < _size; i++)
				{
					int t = _vec[i];
					_vec[i] = prev;
					prev = t;
				}
				delete[] _vec;
				_vec = temp;
			}
		}
	}
}

void Vector::erase(int index)
{
	if (index < _size)
	{
		int next = _vec[_size - 1];
		for (int i = _size - 2; i >= index; i--)
		{
			int temp = _vec[i];
			_vec[i] = next;
			next = temp;
		}
		_size -= 1;
	}
}



