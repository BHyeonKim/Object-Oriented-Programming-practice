#ifndef __ACCOUNT_HANDLER__
#define __ACCOUNT_HANDLER__
#include "Account.h"

class AccountHandler {
private:
	Account* accounts[100];
	static int accountNum;  // 계좌수
public:
	~AccountHandler();
	int showMenu();
	void openNewAccount();
	void openNormalAccount();
	void openHighCreditAccount();
	void deposit();
	void withdraw();
	void showAccountInfo() const;
	int selectAccountType();
};
#endif __ACCOUNT_HANDLER__
