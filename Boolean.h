#pragma once
#include "SimpleValue.h"
class Boolean: public SimpleValue
{
public:
	Boolean(const MyString& strBool);
	 MyString toString() const override;
	 Value* clone() const override;
private:
	bool strBool;
	bool isValid(const MyString& str) const override;
	bool parse(const MyString& str);
};

