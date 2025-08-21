#include "secret_handshake.h"
#include <stdexcept>
#include <algorithm>

namespace secret_handshake {

std::vector<std::string> commands(int secretNumber)
{
    if (secretNumber < 0 || secretNumber > MAX_SECRET_NUMBER)
        throw std::invalid_argument("secret number must be in the range 0-31");

    std::vector<std::string> commandsVector;
    commandsVector.reserve(secretNumber);

    for (const auto& [bin, action] : binToAction)
        if (secretNumber & bin)
            commandsVector.push_back(static_cast<std::string>(action));

    if (secretNumber & REVERSE)
        std::reverse(commandsVector.begin(), commandsVector.end());

    return commandsVector;
}

}  // namespace secret_handshake
