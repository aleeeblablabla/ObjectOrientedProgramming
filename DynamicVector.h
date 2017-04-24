#pragma once

template <class T>
class DynamicVector
{
private:
	T* elems;
	int size;
	int capacity;

public:
	// default constructor for a DynamicVector
	DynamicVector(int capacity = 10);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector<T>& v);
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector<T>& operator=(const DynamicVector& v);

	// Adds an element to the current DynamicVector.
	void add(T e);
	T& getElementFromPos(int& pos);
	int getSize() const;
	T* getAllElems() const;
	int findpos(T e);
	void deleted(int& e);
private:
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);
};
template <class T>
DynamicVector<T>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}
template <class T>
DynamicVector<T>::DynamicVector(const DynamicVector& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}
template <class T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}
template <class T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}
template <class T>
void DynamicVector<T>::add(T e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}
template <class T>
T& DynamicVector<T>::getElementFromPos(int& pos)
{
	if (pos<this->size && pos >= 0)
		return this->elems[pos];
}
template <class T>
int DynamicVector<T>::findpos(T e)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->elems[i].getBreed() == e.getBreed() && this->elems[i].getName() == e.getName() && this->elems[i].getAge() == e.getAge() && this->elems[i].getPhoto() == e.getPhoto())
			return i;
	}
	return -1;
}
template <class T>
void DynamicVector<T>::deleted(int& p)
{
	for (int i = p; i < this->size; i++)
		this->elems[i] = this->elems[i + 1];
	this->size = this->size - 1;
}
template <class T>
void DynamicVector<T>::resize(double factor)
{
	this->capacity *= factor;

	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = els[i];

	delete[] this->elems;
	elems = els;
}
template <class T>
T* DynamicVector<T>::getAllElems()const
{
	return this->elems;
}
template <class T>
int DynamicVector<T>::getSize() const
{
	return this->size;
}
