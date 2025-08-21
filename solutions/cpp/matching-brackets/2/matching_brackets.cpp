#include "matching_brackets.h"
#include <stack>

namespace matching_brackets {

std::unordered_map<char, char> matchingBrackets =
{
    {']', '['},
    {'}', '{'},
    {')', '('},
};

// TODO: add your solution here
bool check(const std::string& bracketsString)
{
    std::stack<char> brackets;

    for (char ch : bracketsString)
    {
        if (std::string("[]{}()").find(ch) == std::string::npos)
            continue;
        
        if ((ch == '[') || (ch == '{') || (ch == '('))
            brackets.push(ch);
        else if (!brackets.empty() && ((ch == ']') || (ch == '}') || (ch == ')')))
        {
            if (brackets.top() == matchingBrackets[ch])
                brackets.pop();
            else
                return false;
        }
        else
            return false;
    }
    
    return (brackets.empty());
}
    
}  // namespace matching_brackets
