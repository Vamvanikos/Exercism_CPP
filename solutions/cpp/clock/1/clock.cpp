#include "clock.h"
#include <iomanip>
#include <sstream>

namespace date_independent {

clock::clock(int hour, int minute) : m_hour(hour), m_minute(minute) {
    normalize();
}

clock clock::at(int hour, int minute) {
    return clock(hour, minute);
}

void clock::normalize() {
    int total_minutes = m_hour * 60 + m_minute;
    total_minutes = ((total_minutes % 1440) + 1440) % 1440;  // Normalize in range [0, 1439]
    m_hour = total_minutes / 60;
    m_minute = total_minutes % 60;
}

std::string clock::to_string() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << m_hour << ":"
        << std::setw(2) << std::setfill('0') << m_minute;
    return oss.str();
}

clock::operator std::string() const {
    return to_string();
}

clock clock::plus(int minutes) const {
    return clock(m_hour, m_minute + minutes);
}

bool clock::operator==(const clock& other) const {
    return m_hour == other.m_hour && m_minute == other.m_minute;
}

bool clock::operator!=(const clock& other) const {
    return !(*this == other);
}

}  // namespace date_independent