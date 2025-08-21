#include "binary.h"
#include <cmath>

namespace binary {

// TODO: add your solution here
int convert(const std::string& binary)
{
    int result = 0;
    size_t i = 0;
    const size_t size = binary.size();
    
    for (char ch : binary)
    {
        if (ch != '1' && ch != '0')
            return 0;

        if (ch == '1')
            result += std::pow(2, size - 1 - i);
        ++i;
    }

    return result;
}

}  // namespace binary
