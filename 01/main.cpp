#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Account;

class AccountHandler {
private:
	Account* accounts[100];
	static int accountNum;  // 계좌수
public:
	~AccountHandler();
	int showMenu();
	void openNewAccount();
	void deposit();
	void withdraw();
	void showAccountInfo();

};

class Account {
private:
	int accountNumber;	// 계좌번호
	char* name;
	int money;
public:
	Account(int, const char*, int);
	Account(const Account&);
	~Account();
	int getAccountNumber() const;
	char* getName() const;
	int getMoney() const;
	void deposit(int money);
	void withdraw(int money);
	void showAccountInfo() const;
};




enum{OPEN_NEW_ACCOUNT=1, DEPOSIT, WITHDRAW, SHOW_ACCOUNT_INFO, EXIT };

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

Account::Account(int accountNumber, const char* name, int money):accountNumber(accountNumber),money(money) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::Account(const Account& account):accountNumber(account.accountNumber),money(account.money)
{
	name = new char[strlen(account.name) + 1];
	strcpy(name, account.name);

}

Account::~Account()
{
	delete[]name;
}

int Account::getAccountNumber() const
{
	return accountNumber;
}

char* Account::getName() const
{
	return name;
}

int Account::getMoney() const
{
	return money;
}

void Account::deposit(int money)
{
	this->money += money;
}

void Account::withdraw(int money)
{
	this->money -= money;
}

void Account::showAccountInfo() const
{
	cout << "계좌ID: " << accountNumber << endl;
	cout << "이름: " << name << endl;
	cout << "잔액: " << money << endl;
}

void AccountHandler::openNewAccount() {
	int accountNumber; //계좌번호
	cout << "[계좌개설]\n";
	cout << "계좌ID: ";		cin >> accountNumber;


	char name[20];
	cout << "이름: ";		cin >> name;

	int money;
	cout << "입금액: ";		cin >> money;
	cout << '\n';

	accounts[accountNum++] = new Account(accountNumber, name, money);
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
		if (accounts[i]->getAccountNumber() == account)
			if (accounts[i]->getMoney() >= money){
				accounts[i]->withdraw(money);
			}else {
				cout << "잔액부족\n" << '\n';
				return;
			}

	cout << "출금완료\n" << '\n';
}

void AccountHandler::showAccountInfo() {
	for (int i = 0; i < accountNum; i++) {
		cout << "계좌ID: " << accounts[i]->getAccountNumber() << '\n';
		cout << "이름 " << accounts[i]->getName() << '\n';
		cout << "잔액: " << accounts[i]->getMoney() << '\n' << '\n';
	}
}


int AccountHandler::accountNum = 0;

AccountHandler::~AccountHandler() {
	delete[] accounts;
}