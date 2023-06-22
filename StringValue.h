#pragma once
#include "Value.h"
struct StringValue: public Value
{
public:
	 StringValue() = default;
	 void print() const override;
	 void parse(sview s) override;
	 Value* clone() const override;
private:
	sview str;
};

