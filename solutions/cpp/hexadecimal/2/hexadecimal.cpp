#include "hexadecimal.h"

namespace hexadecimal {

int convert(const std::string& hex)
{
    int decimal = 0;
    for (char digit : hex)
    {
        if (std::isdigit(digit))
            decimal = decimal << 4 | (digit - '0');
        else 
        {
            char upper = std::toupper(digit);
            if (upper >= 'A' && upper <= 'F')
                decimal = decimal << 4 | (upper - 'A' + 10);
            else
                return 0;
        }
    }

    return decimal;
}

}  // namespace hexadecimal
