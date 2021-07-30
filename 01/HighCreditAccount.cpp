#include "BankingCommonDecl.h"
#include "HighCreditAccount.h"
#include "AccountException.h"

HighCreditAccount::HighCreditAccount(int accountNumber, String name, int money, double interest_rate, int credit) : Account(accountNumber, name, money), interest_rate(interest_rate), credit(credit) {}
HighCreditAccount::HighCreditAccount(const HighCreditAccount& highCreditAccount) : Account(highCreditAccount), interest_rate(highCreditAccount.interest_rate), credit(highCreditAccount.credit) {}
void HighCreditAccount::deposit(int money) {
	if (money < 0)
		throw MinusException(money);
	int addional_interest = 0;
	switch (credit) {
	case 1:
		addional_interest = CREDIT::A;
		break;
	case 2:
		addional_interest = CREDIT::B;
		break;
	case 3:
		addional_interest = CREDIT::C;
		break;
	default:
		break;
	}
	Account::deposit(money);
	Account::deposit(money * (interest_rate / 100.0));	
	Account::deposit(money * (addional_interest / 100.0));
}