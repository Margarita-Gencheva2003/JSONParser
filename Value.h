#pragma once
#include "sview.h"
struct Value
{
public:
	virtual ~Value() = default;
	virtual void print() const = 0;
	virtual void parse(sview s) = 0;
	virtual Value* clone() const = 0;
};

