#include "DepthParser.h"
namespace {
    void popFromStack(stack<char>& lev, char bracket) {
        if (!lev.empty() && lev.peek() ==  bracket) {
            lev.pop();
        }
        else {
            throw std::runtime_error("Malformed JSON: bracket mismatch");
        }
    }
}
size_t DepthParser::level() const
{
    return levels.size();
}

void DepthParser::process(char ch)
{
    if (isInString) {
        if (ch != '\"') {
            return;
        }
        isInString = false;
        return;
    }
    switch (ch)
    {
    case '{':
        levels.push(ch);
        break;
    case '}':
        popFromStack(levels, '{');
        break;
    case '[':
        levels.push(ch);
        break;
    case ']':
        popFromStack(levels, '[');
        break;
    case '\"':
        isInString = true;
        break;
    default:
        break;
    }
}
