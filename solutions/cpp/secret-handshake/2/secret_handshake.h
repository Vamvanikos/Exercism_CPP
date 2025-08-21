#if !defined(SECRET_HANDSHAKE_H)
#define SECRET_HANDSHAKE_H
#include <string>
#include <vector>
#include <array>

namespace secret_handshake {

inline constexpr std::array<std::string_view, 4> actions = { 
    "wink",
    "double blink",
    "close your eyes",
    "jump"
};
// TODO: add your solution here
std::vector<std::string> commands(int number);

}  // namespace secret_handshake

#endif  // SECRET_HANDSHAKE_H
