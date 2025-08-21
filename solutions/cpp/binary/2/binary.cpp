#include "binary.h"

namespace binary {

// TODO: add your solution here
int convert(const std::string& binary)
{
    int result = 0;
    for (char ch : binary)
    {
        if (ch != '1' && ch != '0')
            return 0;

        result = (result << 1) | (ch - '0');
    }

    return result;
}

}  // namespace binary
