#ifndef __BANKING_COMMON_DECL__
#define __BANKING_COMMON_DECL__
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//신용등급
namespace CREDIT {
	enum { A = 7, B = 4, C = 2 };
}
//선택 매뉴
enum { OPEN_NEW_ACCOUNT = 1, DEPOSIT, WITHDRAW, SHOW_ACCOUNT_INFO, EXIT };

//계좌종류
enum { NORMAL_ACCOUNT = 1, HIGH_CREDIT_ACCOUNT };

#endif __BANKING_COMMON_DECL__
