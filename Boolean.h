#pragma once
#include "Value.h"
struct BooleanValue: public Value
{
public:
	BooleanValue() = default;
	void print() const override;
	void parse(sview s) override;
	Value* clone() const override;
private:
	bool value;
};

