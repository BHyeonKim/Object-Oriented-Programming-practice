#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#include "Account.h"

class NormalAccount : public Account {//보통예금계좌
private:
	double interest_rate;
public:
	NormalAccount(int, const char*, int, double);
	NormalAccount(const NormalAccount&);
	virtual void deposit(int money);
};

#endif __NORMAL_ACCOUNT_H__
