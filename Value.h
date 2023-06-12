#pragma once
#include "MyString.h"
/*with help of chatGPT*/
class Value {
public:
	virtual ~Value() = default;
	virtual MyString toString() const = 0;
	virtual Value* clone() const = 0;
	virtual void change(const MyString& newStr) = 0;
};
