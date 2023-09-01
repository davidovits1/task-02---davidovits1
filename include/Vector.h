#pragma once
const int FIRSTMAX = 128;
/// <summary>
/// class of vector
/// </summary>
class Vector
{
	int* vec;
	int size;
	int capacity;

	void set(Vector v);

	void set(int size, int* v);

	/// <summary>
	/// copy vek to temp
	/// </summary>
	/// <param name="temp">new vector of Vector</param>
	/// <returns>new vector</returns>
	int* copy(int* temp);

	/// <summary>
	/// Multiply the capacity by 2 if it is less than 128 otherwise multiply by 1.5
	/// </summary>
	/// <param name="capa">size of old capasity</param>
	/// <param name="n">size of the desired number of values</param>
	/// <returns>new capasity</returns>
	int insertCapacity(int capa, int n);



public:
	//defult ctor
	Vector(int size = 0, int value = 0);

	//copy ctor
	Vector(const Vector& v);

	Vector(int size, int* arr);

	~Vector();
	
	//Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
	int* data();

	//Returns whether the vector is empty (i.e. whether its size is 0).
	bool empty() const;

	//Returns the number of elements in the vector.
	int Size() const;

	//Returns the size of the storage space currently allocated for the vector, expressed in terms of elements
	int Capacity() const;

	//Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
	void clear();

	/// <summary>
	/// Resizes the container so that it contains n elements.
	/// </summary>
	/// <param name="n">new size of container</param>
	/// <param name="val">optional value for the new values</param>
	void resize(int n, int val = 0);

	//Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ.
	void swap(const Vector& v);

	/// <summary>
	/// Adds a new element at the end of the vector, after its current last element.
	///  The content of val is copied (or moved) to the new element.
	/// </summary>
	/// <param name="val">value</param>
	void push_back(const int val);
	
	//Removes the last element in the vector, effectively reducing the container size by one.
	void pop_back();

	//Inserting a value into the vector at the position of the index 
	void insert(int index, int val);

	//Deleting a member from the vector instead of the index
	void erase(int index);

	Vector operator=(const Vector& v);

	int& operator[](int i);

	bool operator==(const Vector& v);

	Vector operator+(Vector v);

	void operator+=(Vector v);

	void operator+=(int num);

	void operator-=(int num);

	void operator*=(int num);

	void operator/=(int num);
	
};
