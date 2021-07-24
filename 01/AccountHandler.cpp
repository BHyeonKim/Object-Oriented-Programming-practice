#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

int AccountHandler::accountNum = 0;

int AccountHandler::showMenu() {
	int select;

	cout << " -----Menu-----\n";
	cout << "1. 계좌개설\n";
	cout << "2. 입금\n";
	cout << "3. 출금\n";
	cout << "4. 계좌정보 전체 출력\n";
	cout << "5. 프로그램 종료\n";
	cout << "선택: "; cin >> select;
	cout << '\n';

	return select;
}

void AccountHandler::openNewAccount() {
	int select = selectAccountType();
	if (select == 0)
		return;
	switch (select) {
	case NORMAL_ACCOUNT:
		openNormalAccount();
		break;
	case HIGH_CREDIT_ACCOUNT:
		openHighCreditAccount();
		break;
	default:
		cout << "ILLGAL SELECTION...\n";
		break;
	}
}

void AccountHandler::deposit() {
	int account;
	int money;
	cout << "계좌ID: ";		cin >> account;
	cout << "입금액: ";		cin >> money;

	for (int i = 0; i < accountNum; i++)
		if (accounts[i]->getAccountNumber() == account)
			accounts[i]->deposit(money);

	cout << "입금완료\n\n";
}

void AccountHandler::withdraw() {
	int account;
	int money;
	cout << "계좌ID: ";		cin >> account;
	cout << "출금액: ";		cin >> money;

	for (int i = 0; i < accountNum; i++)
		if (accounts[i]->getAccountNumber() == account) {
			if (accounts[i]->withdraw(money) == 0) {
				cout << "잔액부족" << endl << endl;
				return;
			}

			cout << "출금완료\n" << '\n';
		}
	cout << "유효하지 않은 ID" << endl;
}

void AccountHandler::showAccountInfo() const{
	for (int i = 0; i < accountNum; i++) {
		accounts[i]->showAccountInfo();
		cout << endl;
	}
}




int AccountHandler::selectAccountType() {
	int select = 0;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: ";	cin >> select;
	if (select == 1)
		return 1;
	if (select == 2)
		return 2;
	return 0;
}

void AccountHandler::openNormalAccount() {
	int accountNumber; //계좌번호
	cout << "[보통예금계좌 개설]\n";
	cout << "계좌ID: ";		cin >> accountNumber;


	char name[20];
	cout << "이름: ";		cin >> name;

	int money;
	cout << "입금액: ";		cin >> money;

	double interest_rate;
	cout << "이자율: ";		cin >> interest_rate;

	accounts[accountNum++] = new NormalAccount(accountNumber, name, money, interest_rate);
}

void AccountHandler::openHighCreditAccount() {
	int accountNumber; //계좌번호
	cout << "[신용신뢰계좌 개설]\n";
	cout << "계좌ID: ";		cin >> accountNumber;


	char name[20];
	cout << "이름: ";		cin >> name;

	int money;
	cout << "입금액: ";		cin >> money;


	double interest_rate;
	cout << "이자율: ";		cin >> interest_rate;

	int credit; // 신용등급
	cout << "신용등급(1 to A, 2 to B, 3 to C):";		cin >> credit;
	accounts[accountNum++] = new HighCreditAccount(accountNumber, name, money, interest_rate, credit);
}

AccountHandler::~AccountHandler() {
	for(int i=0; i < accountNum; i++)
	delete accounts[i];
}