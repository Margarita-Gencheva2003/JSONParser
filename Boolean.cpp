#include "Boolean.h"
#include <stdexcept>
#include <iostream>

void BooleanValue::print() const
{
	std::cout << value << " ";
}

void BooleanValue::parse(sview s)
{
	size_t len = s.length();
	
	if (len == 4) {
		if (s[0] == 't' && s[1] == 'r' && s[2] == 'u' && s[3] == 'e')
			value = true;
		else if (s[0] == 'n' && s[1] == 'u' && s[2] == 'l' && s[3] == 'l')
			value = NULL;
	}
	else if (len == 5) {
		if (s[0] == 'f' && s[1] == 'a' && s[2] == 'l' && s[3] == 's' && s[4] == 'e')
			value = false;
	}
	else {
		throw std::runtime_error("invalid boolean");
	}
}

Value* BooleanValue::clone() const
{
	return new BooleanValue(*this);
}
