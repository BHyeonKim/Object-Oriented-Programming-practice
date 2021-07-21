#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Account {
private:
	int accountNumber;	// 계좌번호
	char* name;
	int money;
public:
	Account(int, const char*, int);
	Account(const Account&);
	~Account();
	int getAccountNumber();
	char* getName();
	int getMoney();
	void deposit(int money);
	void withdraw(int money);
};

int showMenu();
void openNewAccount();
void deposit();
void withdraw();
void showAccountInfo();

Account* accounts[100];
int accountNum = 0;  // 계좌수


enum{OPEN_NEW_ACCOUNT=1, DEPOSIT, WITHDRAW, SHOW_ACCOUNT_INFO, EXIT };
int main() {
	int select;

	while (true) {
		select = showMenu();

		switch (select){
		case OPEN_NEW_ACCOUNT:	//계좌개설
			openNewAccount();
			break;
		case DEPOSIT: //입금
			deposit();
			break;
		case WITHDRAW:	//출금
			withdraw();
			break;
		case SHOW_ACCOUNT_INFO:	//계좌정보 전체 출력
			showAccountInfo();
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

int showMenu() {
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

int Account::getAccountNumber()
{
	return accountNum;
}

char* Account::getName()
{
	return name;
}

int Account::getMoney()
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

void openNewAccount() {
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

void deposit() {
	int account;
	int money;
	cout << "계좌ID: ";		cin >> account;
	cout << "입금액: ";		cin >> money;

	for (int i = 0; i < accountNum; i++)
		if (accounts[i]->getAccountNumber() == account)
			accounts[i]->deposit(money);

	cout << "입금완료\n\n";
}

void withdraw() {
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

void showAccountInfo() {
	for (int i = 0; i < accountNum; i++) {
		cout << "계좌ID: " << accounts[i]->getAccountNumber() << '\n';
		cout << "이름 " << accounts[i]->getName() << '\n';
		cout << "잔액: " << accounts[i]->getMoney() << '\n' << '\n';
	}
}