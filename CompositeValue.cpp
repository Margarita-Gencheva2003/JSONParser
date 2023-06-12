#include "CompositeValue.h"

CompositeValue::CompositeValue(const CompositeValue& other)
{
	copyFrom(other);
}

CompositeValue& CompositeValue::operator=(const CompositeValue& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

void CompositeValue::addValue(Value* v)
{
	this->values.push_back(v);
}

MyString CompositeValue::toString() const
{
	size_t len = this->values.size();
	MyString result;
	for (size_t i = 0; i < len; i++)
	{
		result += this->values[i]->toString();
		result += " ";
	}
	return result;
}

void CompositeValue::change(const MyString& newStr)//i have not still idea for this implementation
{
	size_t len = this->values.size();
	for (size_t i = 0; i < len; i++)
	{
		this->values[i]->change(newStr);
	}
}

CompositeValue::~CompositeValue()
{
	free();
}

void CompositeValue::copyFrom(const CompositeValue& other)
{
	size_t len = other.values.size();
	for (size_t i = 0; i < len; i++)
	{
		this->values[i] = other.values[i]->clone();
	}
}

Value* CompositeValue::clone() const
{
	return new CompositeValue(*this);
}

void CompositeValue::free()
{
	size_t len = values.size();
	for (size_t i = 0; i < len; i++)
	{
		delete values[i];
	}
	
}
