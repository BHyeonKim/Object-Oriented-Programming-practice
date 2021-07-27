#include "String.h"

String::String()
{
	len = 0;
	str = NULL;
}

String::String(const char* str)
{
	len = strlen(str) + 1;
	str = new char[len];
	strcpy(this->str, str);
}

String::String(const String& string)
{
	len = string.len;
	str = new char[len];
	strcpy(str, string.str);

}

String::~String()
{
	if(str!=NULL)
		delete[] str;
}

String& String::operator=(const String& string)
{
	// TODO: 여기에 return 문을 삽입합니다.
	if (str != NULL)
		delete[] str;
	len = string.len;
	str = new char[len];
	strcpy(str, string.str);
	return *this;
}

String& String::operator+=(const String& string)
{
	// TODO: 여기에 return 문을 삽입합니다.
	String temp;
	temp.len = len + string.len - 1;
	temp.str = new char[len];
	strcpy(temp.str, str);
	strcat(temp.str, string.str);

	if (str != NULL)
		delete[] str;
	str = temp.str;
	len = temp.len;
	return *this;
}

bool String::operator==(const String& string)
{
	return strcmp(str, string.str) ? false : true;
}

String String::operator+(const String& string)
{
	char* tempstr = new char[len + string.len - 1];
	strcpy(tempstr, str);
	strcat(tempstr, string.str);

	String temp(tempstr);
	delete[] tempstr;
	return temp;
}

ostream& operator<<(ostream& os, const String& string)
{
	// TODO: 여기에 return 문을 삽입합니다.
	os << string.str;
	return os;
}

istream& operator>>(istream& is, String& str)
{
	// TODO: 여기에 return 문을 삽입합니다.
	char temp[100];
	is >> temp;
	str = String(temp);
	return is;
}
