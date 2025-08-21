#include "binary.h"
#include <cmath>

namespace binary {

int convert(const std::string& binary)
{
    int decimal = 0;
    for (char bin : binary)
    {
        if (bin != '1' && bin != '0')
            return 0;
        
        decimal = decimal << 1 | (bin - '0');
    }
    
    return decimal;
}

}  // namespace binary
