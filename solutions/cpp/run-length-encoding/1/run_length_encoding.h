#pragma once
#include <string>

namespace run_length_encoding {

std::string encode(const std::string& inputString);
std::string decode(const std::string& inputString);

inline std::string addEncode(const char encodeCh, const int count)
{
    std::string result;
    if (count > 1)
        result += std::to_string(count);
    result += encodeCh;

    return result;
}

}  // namespace run_length_encoding
