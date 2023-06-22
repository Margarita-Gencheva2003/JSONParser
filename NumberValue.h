#pragma once
#include "Value.h"
struct NumberValue: public Value
{
public:
	NumberValue() = default;
	virtual void print() const override;
	virtual void parse(sview s) override;
	virtual Value* clone() const override;
private:
	double num;
};

