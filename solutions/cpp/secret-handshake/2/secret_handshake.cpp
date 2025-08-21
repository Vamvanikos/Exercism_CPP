#include "secret_handshake.h"
#include <algorithm>

namespace secret_handshake {

// TODO: add your solution here
std::vector<std::string> commands(int number)
{
    std::vector<std::string> handshakes;
    if (number < 1 || number > 31) return handshakes;
    
    for (size_t i = 0; i < actions.size(); ++i)
    {
        if (number & (1 << i))
        {
            handshakes.push_back(static_cast<std::string>(actions[i]));
        }
    }
    
    if (number & (1 << actions.size()))
    {
        std::reverse(handshakes.begin(), handshakes.end());
    }
    
    return handshakes;
}

}  // namespace secret_handshake
