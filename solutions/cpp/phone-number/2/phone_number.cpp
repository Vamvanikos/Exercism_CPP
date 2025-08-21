#include "phone_number.h"
#include <stdexcept>
#include <algorithm>

namespace phone_number {

// TODO: add your solution here
phone_number::phone_number(const std::string& numberStr)
{
    std::copy_if(numberStr.begin(), numberStr.end(), std::back_inserter(m_phone), ::isdigit);

    if (m_phone.size() == ELEVEN_DIGITS)
    {
        if (m_phone[0] != COUNTRY_CODE)
            throw std::domain_error("Poor country code.");
        m_phone.erase(0,1);
    }
    
    if(m_phone.size() != TEN_DIGITS)
    {
        throw std::domain_error("Poor number of digits.");
    }

    if (poor_digit_format(m_phone[0]) || poor_digit_format(m_phone[3]))
        throw std::domain_error("Poor format of 1st or 4th digit.");
}

bool phone_number::poor_digit_format(char ch)
{
    return (ch < DIGIT_FORMAT);
}

std::string phone_number::number() const
{
    return m_phone;
}
    
}  // namespace phone_number
