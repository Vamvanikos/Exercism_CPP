#include "luhn.h"
#include <cctype>
#include <algorithm>
#include <vector>

namespace luhn {

// TODO: add your solution here
bool valid(std::string cardNum)
{
    std::vector<int> cardDigits;

    cardNum.erase(std::remove(cardNum.begin(), cardNum.end(), ' '), cardNum.end());
    
    if (cardNum.length() < 2) { return false; }
    
    for (char ch : cardNum)
    {
        if (!std::isdigit(ch)) { return false; }
        else
        {
            int digit = ch - '0';
            cardDigits.push_back(digit);
        }
    }

    bool fl = false;
    int sum = 0;
    for (int i = cardDigits.size() - 1; i >= 0; i--)
    {
        if (!fl)
        {
            sum += cardDigits[i];
            fl = true;
        }
        else
        {
            cardDigits[i] = cardDigits[i] * 2;
            if (cardDigits[i] > 9) { cardDigits[i] -= 9; }
            sum += cardDigits[i];
            fl = false;
        }
    }

    if (!(sum % 10)) { return true; }
    else { return false; }
}

}  // namespace luhn
