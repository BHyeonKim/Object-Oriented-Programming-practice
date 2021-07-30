#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__
#include <iostream>
using namespace std;
class MinusException {
private:
	int exval; // 예외금액
public:
	MinusException(int val) :exval(val) {}
	void ShowExceptionInfo() const {
		cout << "입출금액 " << exval << "은 유효하지 않습니다...\n";
	}
};

class InsuffException {
private:
	int balance; //잔액
	int reqval;	//출금액
public:
	InsuffException(int bal, int req) :balance(bal), reqval(req) {}
	void ShowExceptionInfo() const {
		cout << "잔액에서 " << reqval - balance << "가 부족합니다...\n";
	}
};
#endif
