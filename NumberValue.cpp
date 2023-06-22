#include "NumberValue.h"
#include <iostream>
#include <cstdlib>

void NumberValue::print() const
{
    std::cout << num << " ";
}
void NumberValue::parse(sview s)
{
    sview trimmed = s.trim();
    size_t len = trimmed.length();
    char* buffNum = new char[len];
    for (size_t i = 0; i < len; i++)
    {
        buffNum[i] = trimmed[i];
    }
    num = std::atof(buffNum);
    delete[] buffNum;
}

Value* NumberValue::clone() const
{
    return new NumberValue(*this);
}
