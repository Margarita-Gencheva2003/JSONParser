#include <iostream>
#include "Value.h"
#include "ArrayValue.h"
#include "Object.h"
#include "Boolean.h"
#include "NumberValue.h"
#include "StringValue.h"
#include "Manager.h"
#include <fstream>
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
	Manager m;
	std::cout << "Import file name of json:";
	char file[100];
	std::cin >> file;
	std::ifstream ifs(file);
	m.open(ifs);
	m.print();
	ifs.close();
}