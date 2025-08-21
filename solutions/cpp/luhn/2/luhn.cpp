#include "luhn.h"

namespace luhn {

bool valid(const std::string& cardNumber)
{
    std::string strippedNumber;
    strippedNumber.reserve(cardNumber.size());
    for (char ch : cardNumber)
    {
        if (ch == ' ')
            continue;
        if (!std::isdigit(ch))
            return false;
        strippedNumber += ch;
    }

    if (strippedNumber.size() < 2)
        return false;

    int sum = 0;
    int isDoubled = false;
    for (auto it = strippedNumber.rbegin(); it != strippedNumber.rend(); ++it)
    {
        int digit = *it - '0';
        if (isDoubled)
        {
            digit *= 2;
            if (digit > 9)
                digit -= 9;
        }
        sum += digit;
        isDoubled = !isDoubled;
    }

    return sum % 10 == 0;
}

}  // namespace luhn
