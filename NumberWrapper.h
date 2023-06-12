#pragma once
#include "MyString.h"
#include "SimpleValue.h"
class NumberWrapper: public SimpleValue
{
public:
	NumberWrapper(const MyString& str);
    MyString toString() const override;
	void change(const MyString& newStr) override;
	Value* clone() const;
private:
	double num;
	double parse(const MyString& str);
	bool isValid(const MyString& str) const override;
};

