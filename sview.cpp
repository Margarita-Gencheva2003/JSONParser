#include "sview.h"
#include <stdexcept>
#include <iostream>
sview::sview(): begin(nullptr), end(nullptr) {}

sview::sview(char* begin, char* end): begin(begin), end(end) {}

sview sview::ltrim() const
{
	if (begin > end)
		throw std::invalid_argument("begin > end");
	char* current = begin;
	while (current < end) {
		if (std::isspace(*current) == 0)
			break;
		++current;
	}
	return { current, end };
}

sview sview::rtrim() const
{
	if (begin > end)
		throw std::invalid_argument("begin > end");
	char* current = end - 1;
	while (current > begin &&
		std::isspace(*current) != 0)
		--current;
	return { begin, current + 1 };
}

sview sview::trim() const
{
	return ltrim().rtrim();
}

void sview::print() const
{
	size_t len = end - begin;
	char* current = begin;
	for (size_t i = 0; i < len; i++) {
		std::cout << *current;
		++current;
	}
	std::cout << std::endl;
}

char sview::operator[](size_t idx) const
{//Angel55 repo
	return begin[idx];
}

 char* sview::beginPtr() const
{
	return begin;
}

 char* sview::endPtr() const
{
	return end;
}

size_t sview::length() const
{
	return end - begin;
}
