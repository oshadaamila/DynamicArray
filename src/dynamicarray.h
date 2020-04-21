#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <array>
#include <iostream>
#include <string>
#include <exception>

using namespace std;

template <typename T>
class DynamicArray
{
private:
	T *data;
	int filled_size, max_size;

public:
	DynamicArray();
	~DynamicArray();
	void append(T obj);
	int getSize();
	T get(int index);
	T operator [](int index);
	int find(T obj);
};

template <typename T>
DynamicArray<T>::DynamicArray() {
	//creates a size 1 array
	this->data = new T[1];
	this->filled_size = 0;
	this->max_size = 1;

}

template <typename T>
void DynamicArray<T>::append(T obj) {
	if (this->filled_size == this->max_size) {
		//create a new array and enter values
		T *temp = new T[filled_size *2];
		for (int i = 0; i < filled_size * 2; i++) {
			if (i < filled_size) {
				temp[i] = std::move(this->data[i]);
			}
		}
		delete [] this->data;
		this->data = temp;
		this->data[filled_size] = obj;
		this->max_size = this->filled_size*2;
		filled_size = filled_size + 1;
	}
	else {
		this->data[filled_size] = obj;
		filled_size = filled_size + 1;
	}

}

template <typename T>
DynamicArray<T>::~DynamicArray() {
	delete [] this->data;
}

template <typename T>
int DynamicArray<T>::getSize() {
	return this->filled_size;
}

template <typename T>
T DynamicArray<T>::get(int index) {
	if (index < this->filled_size && index>= 0) {
		return this->data[index];
	}else{
		throw "Index out of range";
	}
}

template <typename T>
T DynamicArray<T>::operator[](int index) {
	return this->get(index);
}

template <typename T>
int DynamicArray<T>::find(T obj) {
	for (int i = 0; i < filled_size;i++) {
		if (this->data[i] == obj) {
			return i;
		}
	}
	return -1;

}

#endif