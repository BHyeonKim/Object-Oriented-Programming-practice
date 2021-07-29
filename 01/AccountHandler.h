#ifndef __ACCOUNT_HANDLER__
#define __ACCOUNT_HANDLER__
#include "Account.h"
#include "BankingCommonDecl.h"
#include "BoundCheckArray.h"
#include "String.h"

class AccountHandler {
private:
	BoundCheckArray<Account*> accountArr;
	int accountNum;  // 계좌수
public:
	AccountHandler();
	int showMenu();
	void openNewAccount();
	void openNormalAccount();
	void openHighCreditAccount();
	void deposit();
	void withdraw();
	void showAccountInfo() const;
	int selectAccountType();
	
	~AccountHandler();
};
#endif __ACCOUNT_HANDLER__
