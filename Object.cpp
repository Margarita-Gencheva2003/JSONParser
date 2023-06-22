#include "Object.h"
#include <iostream>
#include "DepthParser.h"
Value* factory(sview s);
ObjectValue::ObjectValue(const ObjectValue& other)
{
	copyFrom(other);
}

ObjectValue& ObjectValue::operator=(const ObjectValue& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

void ObjectValue::print() const
{
	size_t len = keys.size();
	for (size_t i = 0; i < len; i++) {
		std::cout << "Key:";
		keys[i].print();
		std::cout << "Value:";
		values[i]->print();
		std::cout << std::endl;
	}
}

void ObjectValue::parse(sview s)//copied from a person outside fmi
{
	size_t len = s.length();
	if (len == 0)
		throw std::runtime_error("length == 0 at key-value parsing");
	char* kvPairBegin = s.beginPtr();
	char* kvPairEnd = s.beginPtr();
	do {
		DepthParser dp;
		for (; kvPairEnd < s.endPtr(); kvPairEnd++) {
			dp.process(*kvPairEnd);
			if (*kvPairEnd == ',' && dp.level() == 0)
				break;
		}
		parseKeyValuePair({kvPairBegin, kvPairEnd});//copied from a person outside fmi
		kvPairEnd++;
		kvPairBegin = kvPairEnd;
	} while (kvPairEnd < s.endPtr());
}

Value* ObjectValue::clone() const
{
	return new ObjectValue(*this);
}

ObjectValue::~ObjectValue()
{
	free();
}

void ObjectValue::copyFrom(const ObjectValue& other)
{
	size_t len = other.values.size();
	for (size_t i = 0; i < len; i++) {
		this->values[i] = other.values[i]->clone();
	}
}

void ObjectValue::free()
{
	size_t len = values.size();
	for (size_t i = 0; i < len; i++)
	{
		delete values[i];
	}
}

void ObjectValue::parseKeyValuePair(sview s)
{
	char* keyEnd = s.beginPtr();
	for (; keyEnd < s.endPtr(); keyEnd++)
	{
		if (*keyEnd == ':')
			break;
	}
	if (keyEnd == s.endPtr()) {
		throw std::runtime_error("Malformed JSON: no value");
	}
	sview key = sview{ s.beginPtr(), keyEnd }.trim();
	keys.push_back(key);
	values.push_back(factory(sview{ keyEnd + 1, s.endPtr() }.trim()));
}
