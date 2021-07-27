#ifndef __ACCOUNT_HANDLER__
#define __ACCOUNT_HANDLER__
#include "Account.h"
#include "BankingCommonDecl.h"
#include "AccountArray.h"
#include "String.h"

class AccountHandler {
private:
	BoundCheckAccountPtrArray accountArr;
	static int accountNum;  // 계좌수
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
