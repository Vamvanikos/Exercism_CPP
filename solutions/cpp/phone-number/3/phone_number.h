#pragma once
#include <string>

namespace phone_number {

inline constexpr char COUNTRY_CODE = '1';
inline constexpr char DIGITS_BOUND = '2';
inline constexpr int TEN_DIGITS = 10;
    
    
class phone_number {
public:
    phone_number(const std::string& number);
    std::string number() const;

private:
    bool invalid_digits(const char digit);
    
    std::string m_number;
};

}  // namespace phone_number
