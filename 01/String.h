#ifndef __STRING_H__
#define __STRING_H__
#include "BankingCommonDecl.h"
class String {
private:
	int len;
	char* str;
public:
	String();
	String(const char* str);
	String(const String& string);
	~String();
	String& operator=(const String& string);
	String& operator+=(const String& string);
	bool operator==(const String& string);
	String operator+(const String& string);

	friend ostream& operator<<(ostream& os, const String& string);
	friend istream& operator>>(istream& is, String& str);
};
#endif
