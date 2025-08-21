#include "secret_handshake.h"
#include <algorithm>

namespace secret_handshake {

// TODO: add your solution here
std::vector<std::string> commands(int number)
{
    std::vector<std::string> handshakes;
    if (number & 0b1) handshakes.push_back("wink"); 
    if (number & 0b10) handshakes.push_back("double blink");
    if (number & 0b100) handshakes.push_back("close your eyes");
    if (number & 0b1000) handshakes.push_back("jump");
    if (number & 0b10000) std::reverse(handshakes.begin(), handshakes.end());
    
    return handshakes;
}

}  // namespace secret_handshake
