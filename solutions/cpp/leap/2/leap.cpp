#include "leap.h"
#include <stdexcept>

namespace leap {

bool is_leap_year(int year)
{
    if (year < 0)
        throw std::invalid_argument("Year can't be negative.");

    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;

    return year % 4 == 0;
}

}  // namespace leap
