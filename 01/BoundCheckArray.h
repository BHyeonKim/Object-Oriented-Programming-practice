#ifndef __BOUND_CHECK_ARRAY_
#define __BOUND_CHECK_ARRAY_
#include <iostream>
using namespace std;

template <typename T>
class BoundCheckArray {
private:
	T* arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray& arr) {}
public:
	BoundCheckArray(){}
	BoundCheckArray(int length);
	T& operator[](int index);
	T operator[](int index) const;
	int GetLength() const;
	~BoundCheckArray();
};

template<typename T>
BoundCheckArray<T>::BoundCheckArray(int length):arrlen(length){
	arr = new T[arrlen];
}

template <typename T>
T& BoundCheckArray<T>::operator[](int index) {
	if (index < 0 || index >= arrlen) {
		cout << "Array index out of bound exception...\n";
		exit(0);
	}
	return arr[index];
}

template <typename T>
T BoundCheckArray<T>::operator [](int index)const {
	if (index < 0 || index >= arrlen) {
		cout << "Array index out of bound exception...\n";
		exit(0);
	}
	return arr[index];
}

template <typename T>
int BoundCheckArray<T>::GetLength()const{
	return arrlen;
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray(){
	delete[] arr;
}
#endif

