#include "StringValue.h"
#include <stdexcept>

void StringValue::print() const
{
    str.print();
}

void StringValue::parse(sview s)
{
    size_t len = s.length();
    if (s[0] != '\"' || s[len - 1] != '\"')
        throw std::runtime_error("string is not correct");
    str = s;
}

Value* StringValue::clone() const
{
    return new StringValue(*this);
}
