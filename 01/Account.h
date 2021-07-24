#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__


class Account {
private:
	int accountNumber;	// 계좌번호
	char* name;
	int money;
public:
	Account(int, const char*, int);
	Account(const Account&);

	int getAccountNumber() const;
	virtual void deposit(int money);
	int withdraw(int money);
	void showAccountInfo() const;

	~Account();
};

#endif __ACCOUNT_H__