#include <iostream>
#include "Value.h"
#include "ArrayValue.h"
#include "Object.h"
#include "Boolean.h"
#include "NumberValue.h"
#include "StringValue.h"

Value* factory(sview s) {
	s = s.trim();
	size_t len = s.length();
	if (*s.beginPtr() == '{') {
		if (*(s.endPtr() - 1) != '}') {
			throw std::runtime_error("Malformed JSON: object");
		}
		sview payload {s.beginPtr() + 1, s.endPtr() - 1};
		ObjectValue* ov = new ObjectValue();
		ov->parse(payload.trim());
		return ov;
	}
	if (*s.beginPtr() == '[') {
		if (*(s.endPtr() - 1) != ']') {
			throw std::runtime_error("Malformed JSON: array");
		}
		sview payload{ s.beginPtr() + 1, s.endPtr() - 1 };
		ArrayValue* av = new ArrayValue();
		av->parse(payload.trim());
		return av;
	}
	if (std::isdigit(*s.beginPtr())) {
		NumberValue* nv = new NumberValue();
		nv->parse(s);
		return nv;
	}
	if (*s.beginPtr() == '\"') {
		if (*(s.endPtr() - 1) != '\"') {
			throw std::runtime_error("Malformed JSON: string");
		}
		StringValue* sv = new StringValue();
		sv->parse(s);
		return sv;
	}
	if (len == 4 || len == 5) {
		BooleanValue* bv = new BooleanValue();
		bv->parse(s);
		return bv;
	}
	throw std::runtime_error("Malformed JSON: unknown");
}
int main() {
	char arr[] = "{  \"Cities\" : {\"sofia\": 1, \"plovdiv\" : 2}, \"Temps\": [10, 20, 30] }";
//	char arr[] = R"({"Temperature": {"sofia": 22 , "plovdiv": 32}, "stars" : 4.5})";
	sview s(arr, arr + strlen(arr));
	try {
		Value* value = factory(s);
		value->print();
		delete value;
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	
}