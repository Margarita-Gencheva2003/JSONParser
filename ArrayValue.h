#pragma once
#include "Value.h"
#include "vector.hpp"
struct ArrayValue: public Value
{
public:
	ArrayValue() = default;
	ArrayValue(const ArrayValue& other);
	ArrayValue& operator=(const ArrayValue& other);
	void print() const override;
	void parse(sview s) override;
	Value* clone() const override;
	~ArrayValue();
private:
	vector<Value*> values;
	void copyFrom(const ArrayValue& other);
	void free();
};

