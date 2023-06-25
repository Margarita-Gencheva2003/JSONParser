#pragma once
#include "Value.h"
#include <istream>
Value* factory(sview s);
class Manager
{
public:
	Manager() = default;
	~Manager();
	void open(std::ifstream& is);
	void print() const;
	void close() const;
private:
	Value* json = nullptr;
	bool isOpened = false;
	char* buffer = nullptr;
};

