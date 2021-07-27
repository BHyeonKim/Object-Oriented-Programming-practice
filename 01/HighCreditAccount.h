#ifndef __HIGH_CREDIT_ACCOUNT__
#define __HIGH_CREDTI_ACCOUNT__
#include "Account.h"
#include "String.h"

class HighCreditAccount : public Account {//보통예금계좌
private:
	int credit;
	double interest_rate;
public:
	HighCreditAccount(int, String, int, double, int);
	HighCreditAccount(const HighCreditAccount&);
	virtual void deposit(int money);
};

#endif __HIGH_CREDTI_ACCOUNT__
