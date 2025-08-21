#include "matching_brackets.h"
#include <stack>

namespace matching_brackets {

bool check(const std::string& text)
{
    std::stack<char> openBrackets;
    for (char ch : text)
    {
        if (openingBrackets.count(ch) > 0)
            openBrackets.push(ch);
        else if (bracketPairs.count(ch) > 0)
        {
            if (openBrackets.empty() || bracketPairs.at(ch) != openBrackets.top())
                return false;
            openBrackets.pop();
        }
    }

    return openBrackets.empty();
}

}  // namespace matching_brackets
