#pragma once
#include <string>

namespace bob {

void remove_whitespace(std::string& sentence);
bool has_questionmark(const std::string& sentence);
bool has_caps(const std::string& sentence);
bool has_lowcase(const std::string& sentence);
    
std::string hey(const std::string& sentence);

}  // namespace bob
