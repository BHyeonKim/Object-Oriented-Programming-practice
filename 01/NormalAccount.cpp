#include "BankingCommonDecl.h"
#include "NormalAccount.h"

NormalAccount::NormalAccount(int accountNumber, const char* name, int money, double interest_rate) :Account(accountNumber, name, money), interest_rate(interest_rate) {}
NormalAccount::NormalAccount(const NormalAccount& normalAccount) : Account(normalAccount), interest_rate(normalAccount.interest_rate) {}
void NormalAccount::deposit(int money) {
	Account::deposit(money);
	Account::deposit(money * (interest_rate / 100.0));
}