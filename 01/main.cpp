#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main() {
	AccountHandler* accountHandler = new AccountHandler();
	int select;

	while (true) {
		select = accountHandler->showMenu();

		switch (select){
		case OPEN_NEW_ACCOUNT:	//계좌개설
			accountHandler->openNewAccount();
			break;
		case DEPOSIT: //입금
			accountHandler->deposit();
			break;
		case WITHDRAW:	//출금
			accountHandler->withdraw();
			break;
		case SHOW_ACCOUNT_INFO:	//계좌정보 전체 출력
			accountHandler->showAccountInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection\n";
			break;
		}
	}
	return 0;
}