#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include "String.h"

class Account {
private:
	int accountNumber;	// 계좌번호
	String name;
	int money;
public:
	Account(int, String, int);
	Account(const Account&);
	Account& operator=(const Account& account);

	int getAccountNumber() const;
	virtual void deposit(int money);
	int withdraw(int money);
	void showAccountInfo() const;

	~Account();
};

#endif __ACCOUNT_H__