#pragma once
#include "stack.hpp"
struct DepthParser//taken from person outside FMI 
{//(dp is needed to parse objects on the same level,
//it counts opening and closing brackets
public:
	size_t level() const;
	void process(char ch);
private:
	bool isInString{ false };
	stack<char>levels;
};

