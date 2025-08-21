#include "hexadecimal.h"
#include <iostream>

namespace hexadecimal {

// TODO: add your solution here
int convert(std::string hexString)
{
    unsigned int result = 0;

    for (char ch : hexString)
    {
        result *= 16;

        if (std::isdigit(ch))
        {
            result += ch - '0';
        }
        else
        {
            ch = std::toupper(ch);
            if (ch >= 'A' && ch <= 'F')
            {
                result += ch - 'A' + 10;
            }
            else
            {
                std::cout << "Invalid input";
                return 0;
            }
        }
    }

    return result;
}

}  // namespace hexadecimal
