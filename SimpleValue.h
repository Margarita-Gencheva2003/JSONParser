#pragma once
#include "Value.h"
class SimpleValue : public Value
{//abstract class also
protected:
	virtual bool isValid(const MyString& str) const = 0;
};

