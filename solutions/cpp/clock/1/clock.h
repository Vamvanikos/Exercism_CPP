#ifndef CLOCK_H
#define CLOCK_H

#include <string>

namespace date_independent {

class clock {
public:
    static clock at(int hour, int minute);
    clock plus(int minutes) const;

    std::string to_string() const;
    operator std::string() const;

    bool operator==(const clock& other) const;
    bool operator!=(const clock& other) const;

private:
    int m_hour;
    int m_minute;

    clock(int hour, int minute);
    void normalize();
};

}  // namespace date_independent

#endif