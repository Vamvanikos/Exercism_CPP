#include "bob.h"

namespace bob {

// TODO: add your solution here
std::string hey(std::string quest)
{
    std::string resp;
    size_t countUpper = 0, countWhiteSpace = 0, countPunct = 0, countDigit = 0;
    for (char ch : quest)
    {
        if (isupper(ch)) { countUpper++; }
        if (isspace(ch)) { countWhiteSpace++; }
        if (ispunct(ch)) { countPunct++; }
        if (isdigit(ch)) { countDigit++; }
    }

    while ((!quest.empty()) && isspace(quest.back()))
    {
        quest.pop_back();
        countWhiteSpace--;
    }

    if (quest.empty())
    {
        resp = "Fine. Be that way!";
    }
    else
    {
        if ((countUpper != 0) && ((countUpper + countWhiteSpace + countPunct + countDigit) == quest.size()) 
              && (quest[quest.size()-1] == '?'))
        {
            resp = "Calm down, I know what I'm doing!";
        }
        else if ((countUpper != 0) && ((countUpper + countWhiteSpace + countPunct + countDigit) == quest.size()))
        {
            resp = "Whoa, chill out!";
        }
        else if (quest[quest.size()-1] == '?')
        {
            resp = "Sure.";
        }
        else
        {
            resp = "Whatever.";
        }
    }

    return resp;
}

}  // namespace bob
