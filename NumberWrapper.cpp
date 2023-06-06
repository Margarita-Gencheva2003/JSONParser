#include "NumberWrapper.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cmath>
namespace {
	size_t myPow(size_t a, size_t b) {
		size_t result = 1;
		for (size_t i = 0; i < b; i++) {
			result *= a;
		}
		return result;
	}
	size_t calcNumberLen(int num) {//chatGPT
		size_t length = 0;
		int number = abs(num);
		if (number == 0) {
			return 1;
		}
		while (number > 0) {
			number /= 10;
			length++;
		}

		return length;
	}
}
NumberWrapper::NumberWrapper(const MyString& str):num(parse(str)) {}

MyString NumberWrapper::toString() const//internet
{
	std::stringstream ss;
	ss << this->num;
	MyString str = ss.str().c_str();
	return str;
}

Value* NumberWrapper::clone() const
{
	return new NumberWrapper(*this);
}

double NumberWrapper::parse(const MyString& str)//stackoverflow and internet
{
	if (!isValid(str))
		throw std::invalid_argument("read string is not valid number!");
	double result;
	std::stringstream ss(str.c_str());
	ss >> result;
	return result;
}

bool NumberWrapper::isValid(const MyString& str) const
{
	int flagPoint = 0;
	int flagMinus = 0;
	int flagDigits = 0;
	size_t len = str.length();
	for (size_t i = 0; i < len; i++) {
		if (str[i] == '-')
			++flagMinus;
		if (str[i] == '.') {
			++flagPoint;
		}
		if (str[i] >= '0' && str[i] <= '9') {
			++flagDigits;
		}
	}
	if (flagPoint == 1 &&
		(flagMinus == 0 || flagMinus == 1) &&
		((flagDigits + flagMinus) == len || (flagDigits + flagMinus) == len - 1)) {
		return true;
	}
	return false;
}
