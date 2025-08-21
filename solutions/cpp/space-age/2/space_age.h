#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

#include <string>

namespace space_age {

inline constexpr int YEAR_IN_SECONDS = 31'557'600;
inline constexpr double MERCURY_PERIOD = 0.2408467;
inline constexpr double VENUS_PERIOD = 0.61519726;
inline constexpr double MARS_PERIOD = 	1.8808158;
inline constexpr double JUPITER_PERIOD = 11.862615;
inline constexpr double SATURN_PERIOD = 29.447498;
inline constexpr double URANUS_PERIOD = 84.016846;
inline constexpr double NEPTUNE_PERIOD = 164.79132;

class space_age{
public:
    explicit space_age(long ageInSeconds) : secs(ageInSeconds) {};
    long seconds() const;
    double on_earth() const;
    double on_planet(double period) const;
    double on_mercury() const;
    double on_venus() const;
    double on_mars() const;
    double on_jupiter() const;
    double on_saturn() const;
    double on_uranus() const;
    double on_neptune() const;

private:
    long secs;
};

}  // namespace space_age

#endif  // SPACE_AGE_H