#include "isbn_verifier.h"
#include <algorithm>

namespace isbn_verifier {

bool is_valid(const std::string& isbnInput)
{   
    int result;
    std::string checkString = isbnInput;
    if (checkString.back() == 'X')
        result = 10;
    else if (std::isdigit(checkString.back()))
        result = checkString.back() - '0';
    else 
        return false;
    checkString = checkString.substr(0, checkString.size() - 1);
    
    checkString.erase(std::remove(checkString.begin(), checkString.end(), '-'), checkString.end());
    if (checkString.size() != NUM_DIGITS_MINUS_10TH)
        return false;

    int mult = 10;
    for (const char ch : checkString)
    {
        if (!std::isdigit(ch))
            return false;
        
        result += (ch - '0') * mult--; 
    }

    return (result % 11 == 0);
}

}  // namespace isbn_verifier