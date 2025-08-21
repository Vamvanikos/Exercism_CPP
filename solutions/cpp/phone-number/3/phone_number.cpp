#include "phone_number.h"
#include <stdexcept>
#include <algorithm>

namespace phone_number {

phone_number::phone_number(const std::string& number)
{
    m_number.reserve(number.size());
    std::copy_if(number.begin(), number.end(), std::back_inserter(m_number), ::isdigit);

    if (!m_number.empty() && m_number[0] == COUNTRY_CODE)
        m_number = m_number.substr(1);
    
    if (m_number.size() != TEN_DIGITS)
        throw std::domain_error("Invalid size of telephone number.");
        
    if (invalid_digits(m_number[0]) || invalid_digits(m_number[3]))
        throw std::domain_error("Invalid digits in telephone number.");
}

bool phone_number::invalid_digits(const char digit)
{
    return digit < DIGITS_BOUND;
}
    
std::string phone_number::number() const
{
    return m_number;
}


}  // namespace phone_number
