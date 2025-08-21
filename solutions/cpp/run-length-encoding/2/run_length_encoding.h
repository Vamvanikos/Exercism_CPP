#pragma once
#include <string>

namespace run_length_encoding {

std::string encode(const std::string& message);
std::string decode(const std::string& message);

}  // namespace run_length_encoding
