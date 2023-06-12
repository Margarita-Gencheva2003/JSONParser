#pragma once
#include "SimpleValue.h"
class StringWrapper: public SimpleValue
{
public:
	 StringWrapper(const MyString& str);
	 MyString toString() const override;
	 void change(const MyString& newStr) override;
	 Value* clone() const override;
private:
	MyString str;
	bool isValid(const MyString& str) const override;
};


