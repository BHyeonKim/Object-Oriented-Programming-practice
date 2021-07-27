#include "AccountArray.h"


BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len):arrlen(len)
{
	arr = new ACCOUNT_PTR[arrlen];
}

ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[](int idx)
{
	// TODO: 여기에 return 문을 삽입합니다.
	if (0 > idx || arrlen <= idx) {
		cout << "Index out of bound exception...\n";
		exit(1);
	}
	return arr[idx];
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[](int idx) const
{
	if (0 > idx || arrlen <= idx) {
		cout << "Index out of bound exception...\n";
		exit(1);
	}
	return arr[idx];

}

int BoundCheckAccountPtrArray::GetArrLen() const
{
	return arrlen;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray()
{
	delete[] arr;
}
