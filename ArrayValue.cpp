#include "ArrayValue.h"
#include "DepthParser.h"
Value* factory(sview s);
ArrayValue::ArrayValue(const ArrayValue& other)
{
	copyFrom(other);
}

ArrayValue& ArrayValue::operator=(const ArrayValue& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
void ArrayValue::print() const
{
	size_t len = values.size();
	for (size_t i = 0; i < len; i++)
	{
		values[i]->print();
	}
}
void ArrayValue::parse(sview s)
{
	size_t len = s.length();
	if (len == 0)
		throw std::runtime_error("length == 0 at key-value parsing");
	char* vBegin = s.beginPtr();
	char* vEnd = s.beginPtr();
	do {
		DepthParser dp;
		for (; vEnd < s.endPtr(); vEnd++) {
			dp.process(*vEnd);
			if (*vEnd == ',' && dp.level() == 0)
				break;
		}
		sview valueStr{ vBegin, vEnd };
		values.push_back(factory(valueStr));
		vEnd++;
		vBegin = vEnd;
	} while (vEnd < s.endPtr());
}
Value* ArrayValue::clone() const
{
	return new ArrayValue(*this);
}
ArrayValue::~ArrayValue()
{
	free();
}
void ArrayValue::copyFrom(const ArrayValue& other)
{
	size_t len = other.values.size();
	for (size_t i = 0; i < len; i++) {
		this->values[i] = other.values[i]->clone();
	}
}

void ArrayValue::free()
{
	size_t len = values.size();
	for (size_t i = 0; i < len; i++)
	{
		delete values[i];
	}
}