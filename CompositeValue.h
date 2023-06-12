#pragma once
#include "Value.h"
#include "vector.hpp"
class CompositeValue: public Value
{
public:
	CompositeValue() = default;
	CompositeValue(const CompositeValue& other);
	CompositeValue& operator=(const CompositeValue& other);
	void addValue(Value* v);
	MyString toString() const override;
	void change(const MyString& newStr) override;
	~CompositeValue();
private:
	vector<Value*> values;
	void copyFrom(const CompositeValue& other);
	Value* clone() const override;
	void free();
};

