#include <iostream>
using namespace std;

typedef struct {
	int accountNumber;	// 계좌번호
	char* name;
	int deposit;
}Account;

Account accounts[100];
int accountNum = 0;  // 계좌수

int showMenu();

void openNewAccount();
void deposit();
void withdraw();
void showAccountInfo();

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

	return select;
}

void openNewAccount() {
	cout << "[계좌개설]\n";
	cout << "계좌ID: ";		cin >> accounts[accountNum].accountNumber;

	cout << "이름: ";
	char temp[20];
	cin >> temp;
	accounts[accountNum].name = new char[strlen(temp) + 1];

	cout << "입금액: ";		cin >> accounts[accountNum].deposit;
	cout << '\n';

	accountNum++;
}

void deposit() {
	int account;
	int money;
	cout << "계좌ID: ";		cin >> account;
	cout << "입금액: ";		cin >> money;

	for (int i = 0; i < accountNum; i++)
		if (accounts[i].accountNumber == account)
			accounts[i].deposit += money;

	cout << "입금완료\n\n";
}

void withdraw() {
	int account;
	int money;
	cout << "계좌ID: ";		cin >> account;
	cout << "출금액: ";		cin >> money;

	for (int i = 0; i < accountNum; i++)
		if (accounts[i].accountNumber == account)
			if (accounts[i].deposit >= money){
				accounts[i].deposit -= money;
			}else {
				cout << "잔액부족\n\n";
				return;
			}

	cout << "출금완료\n\n";
}

void showAccountInfo() {
	for (int i = 0; i < accountNum; i++) {
		cout << "계좌ID: " << accounts[i].accountNumber << '\n';
		cout << "이름 " << accounts[i].name << '\n';
		cout << "잔액: " << accounts[i].deposit << '\n';
	}
}