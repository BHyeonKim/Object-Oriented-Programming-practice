#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int accountNumber, const char* name, int money) :accountNumber(accountNumber), money(money) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::Account(const Account& account) : accountNumber(account.accountNumber), money(account.money)
{
	name = new char[strlen(account.name) + 1];
	strcpy(name, account.name);

}

Account& Account::operator=(const Account& account)
{
	// TODO: 여기에 return 문을 삽입합니다.
	delete[] name;
	name = new char[strlen(account.name) + 1];
	strcpy(name, account.name);
	accountNumber = account.accountNumber;
	money = account.money;
	
	return *this;
}


int Account::getAccountNumber() const
{
	return accountNumber;
}

void Account::deposit(int money)
{
	this->money += money;
}

int Account::withdraw(int money)
{
	if (this->money < money)
		return 0;
	this->money -= money;
	return money;
	
}

void Account::showAccountInfo() const
{
	cout << "계좌ID: " << accountNumber << endl;
	cout << "이름: " << name << endl;
	cout << "잔액: " << money << endl;
}

Account::~Account()
{
	delete[]name;
}