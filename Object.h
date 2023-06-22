#pragma once
#include "Value.h"
#include "vector.hpp"
struct ObjectValue: public Value
{
public:
	ObjectValue() = default;
	ObjectValue(const ObjectValue& other);
	ObjectValue& operator=(const ObjectValue& other);
	 void print() const override;
	 void parse(sview s) override;//*
	 Value* clone() const override;
	 ~ObjectValue(); 
private:
	vector<sview> keys;
	vector<Value*> values;
	void copyFrom(const ObjectValue& other);
	void free();
	void parseKeyValuePair(sview s);
};

//* parsing logic in this project is taken from person outside fmi