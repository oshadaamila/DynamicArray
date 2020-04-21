#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <typename T>
class DynamicArray
{
private:
	int *data[1];

public:
	DynamicArray();
	int getOne();
};

template <typename T>
DynamicArray<T>::DynamicArray() {

}

template <typename T>
int DynamicArray<T>::getOne() {
	return 1;
}

#endif