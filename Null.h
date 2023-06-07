#pragma once
#include "SimpleValue.h"
class Null: public SimpleValue
{
public:
	Null(const MyString& str);
	MyString toString() const override;
	Value* clone() const override;
private:
	void* myNull;
	bool isValid(const MyString& str) const override;
};

