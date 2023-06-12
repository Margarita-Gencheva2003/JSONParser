#include "StringWrapper.h"

StringWrapper::StringWrapper(const MyString& str)
{
	change(str);
}

MyString StringWrapper::toString() const
{
	return this->str;
}

void StringWrapper::change(const MyString& newStr)
{
	if (isValid(newStr))
		this->str = newStr;
	else
		throw std::invalid_argument("invalid str!");
}

Value* StringWrapper::clone() const
{
    return new StringWrapper(*this);
}

bool StringWrapper::isValid(const MyString& str) const
{
    size_t len = str.length();
	for (size_t i = 0; i < len; i++)
	{
		if (str[i] < '<') {
			return false;
		}
	}
	return true;
}
