#include "isbn_verifier.h"
#include <algorithm>
#include <stdexcept>

namespace isbn_verifier {

bool validDigits(const std::string& isbnCode)
{
    for (size_t i = 0; i < DIGITS_NUM; ++i)
        if (!std::isdigit(static_cast<unsigned char>(isbnCode[i])))
        {
            if (i == LAST_INDEX && isbnCode[i] == 'X')
                return true;
            return false;
        }

    return true;
}
    
bool is_valid(const std::string& isbnCode)
{
    std::string isbnCodeDigits = isbnCode;
    isbnCodeDigits.erase(std::remove(isbnCodeDigits.begin(), isbnCodeDigits.end(),'-'),
                         isbnCodeDigits.end());
    
    if (isbnCodeDigits.size() != DIGITS_NUM)
        return false;
    if (!validDigits(isbnCodeDigits))
        return false;

    int multiplier = 10;
    int formulaSum = 0;
    for (size_t i = 0; i < DIGITS_NUM - 1; ++i)
        formulaSum += (isbnCodeDigits[i] - '0') * multiplier--;

    if (isbnCodeDigits[9] == 'X')
        formulaSum += 10;
    else
        formulaSum += isbnCodeDigits[9] - '0';

    return (formulaSum % 11 == 0);
}

}  // namespace isbn_verifier