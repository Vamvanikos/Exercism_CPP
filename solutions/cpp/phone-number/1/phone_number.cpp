#include "phone_number.h"
#include <stdexcept>

namespace phone_number {

// TODO: add your solution here
phone_number::phone_number(const std::string& numberStr)
{
    for (char ch : numberStr)
    {
        if (std::isdigit(ch)) m_phone += ch;
    }

    if(m_phone.size() == TEN_DIGITS)
    {
        if ((m_phone[0] < DIGIT_FORMAT) || (m_phone[3] < DIGIT_FORMAT))
            throw std::domain_error("Poor format of 1st or 4th digit.");
    }
    else if (m_phone.size() == ELEVEN_DIGITS)
    {
        if (m_phone[0] != COUNTRY_CODE)
            throw std::domain_error("Poor country code.");
        if ((m_phone[1] < DIGIT_FORMAT) || m_phone[4] < DIGIT_FORMAT)
            throw std::domain_error("Poor format of 1st or 4th digit.");
        
        m_phone.erase(0,1);
    }
    else
        throw std::domain_error("Poor number of digits.");
}

std::string phone_number::number() const
{
    return m_phone;
}
    
}  // namespace phone_number
