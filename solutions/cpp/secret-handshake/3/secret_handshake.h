#pragma once
#include <vector>
#include <string>
#include <utility>
#include <array>

namespace secret_handshake {

inline constexpr int MAX_SECRET_NUMBER = 31;
inline constexpr int REVERSE = 0b10000;

inline const std::array<std::pair<int, std::string_view>, 4> binToAction = {{
    {0b00001, "wink"},
    {0b00010, "double blink"},
    {0b00100, "close your eyes"},
    {0b01000, "jump"}
}};

std::vector<std::string> commands(int secretNumber);

}  // namespace secret_handshake
