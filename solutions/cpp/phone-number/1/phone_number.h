#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H
#include <string>

namespace phone_number {

inline constexpr int TEN_DIGITS = 10;
inline constexpr int ELEVEN_DIGITS = 11;
inline constexpr char COUNTRY_CODE = '1';
inline constexpr char DIGIT_FORMAT = '2';

// TODO: add your solution here
class phone_number {
public:
    phone_number(const std::string& numberStr);
    std::string number() const;

private:
    std::string m_phone;
};
    
}  // namespace phone_number

#endif  // PHONE_NUMBER_H