#pragma once
#include "MyString.h"
/*with help of chatGPT*/
class Value {
public:
	virtual ~Value() = default;
	virtual void add(Value* value) = 0;
	virtual void remove(Value* value) = 0;
	virtual const MyString& toString() const = 0;
	virtual bool isSimple() const = 0;
	virtual bool isObject() const = 0;
	virtual bool isArray() const = 0;
	virtual size_t elemInValue() const = 0;
};
