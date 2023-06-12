#include "Null.h"

Null::Null(const MyString& str)
{
	change(str);
}

MyString Null::toString() const
{
	if (myNull == NULL)
		return "null";
	return "non";
}

void Null::change(const MyString& newStr)
{
	if (isValid(newStr)) {
		this->myNull = NULL;
	}
	else {
		throw std::invalid_argument("str is not null");
	}
}

Value* Null::clone() const
{
	return new Null(*this);
}

bool Null::isValid(const MyString& str) const
{
	if (str == "null")
		return true;
	else
		return false;
}
