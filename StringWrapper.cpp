#include "StringWrapper.h"

StringWrapper::StringWrapper(const MyString& str)
{
	if (isValid(str))
		this->str = str;
}

MyString StringWrapper::toString() const
{
	return this->str;
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
		if (str[i] < '0' ||
			(str[i] >= '[' && str[i] <= '`')) {
			return false;
		}
	}
	return true;
}