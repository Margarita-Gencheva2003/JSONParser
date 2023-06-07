#include "Null.h"
#include <stdexcept>
Null::Null(const MyString& str)
{
	if (isValid(str)) {
		this->myNull = NULL;
	}
	else {
		throw std::invalid_argument("str is not null");
	}
}

MyString Null::toString() const
{
	if (myNull == NULL)
		return "null";
	return "non";
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
