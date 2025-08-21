#include "isbn_verifier.h"
#include <algorithm>

namespace isbn_verifier {

bool is_valid(const std::string& isbnInput)
{   
    std::string cleanStr;
    cleanStr.reserve(isbnInput.size());

    for (const char ch : isbnInput)
    {
        if (ch == '-')
            continue;
        if (std::isdigit(ch) || ch == 'X')
            cleanStr.push_back(ch);
        else
            return false;
    }

    if (cleanStr.size() != NUM_DIGITS)
        return false;

    int result = 0;
    for (int i = 0; i < NUM_DIGITS; ++i)
    {
        const char ch = cleanStr[i];
        if (std::isdigit(ch))
            result += (ch - '0') * (10 - i);
        else if (ch == 'X')
        {
            if (i != NUM_DIGITS - 1)
                return false;
            result += 10;
        }
    }

    return (result % 11 == 0);
}

}  // namespace isbn_verifier