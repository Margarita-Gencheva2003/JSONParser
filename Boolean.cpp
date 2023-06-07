#include "Boolean.h"

Boolean::Boolean(const MyString& strBool):strBool(parse(strBool)) {}

MyString Boolean::toString() const
{
    switch (strBool)
    {
    case true:
        return "true";
    case false:
        return "false";
    default:
        return "non";
    }
}

Value* Boolean::clone() const
{
    return new Boolean(*this);
}

bool Boolean::isValid(const MyString& str) const
{
    return str == "true" || str == "false";
}

bool Boolean::parse(const MyString& str)
{
    if (!isValid(str))
        throw std::invalid_argument("str is not boolean");
    if (str == "true")
        return true;
    else 
        return false;
  
}
