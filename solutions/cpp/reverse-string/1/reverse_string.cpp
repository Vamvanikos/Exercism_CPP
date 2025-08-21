#include "reverse_string.h"

namespace reverse_string {

// TODO: add your solution here
std::string reverse_string(std::string str)
{
    for (size_t i = 0; i < str.length()/2; i++)
    {
        char tmp = str[str.length() - i - 1];
        str[str.length() - i - 1] = str[i];
        str[i] = tmp;
    }

    return str;
}

}  // namespace reverse_string
