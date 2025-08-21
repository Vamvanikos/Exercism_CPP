#include "space_age.h"

namespace space_age {

const int YEAR_IN_SECONDS = 31557600;
const double MERCURY_PERIOD = 0.2408467;
const double VENUS_PERIOD = 0.61519726;
const double MARS_PERIOD = 	1.8808158;
const double JUPITER_PERIOD = 11.862615;
const double SATURN_PERIOD = 29.447498;
const double URANUS_PERIOD = 84.016846;
const double NEPTUNE_PERIOD = 164.79132;

// TODO: add your solution here
long space_age::seconds() const
{
    return secs;
}

double space_age::on_earth() const
{
    return (static_cast<double>(space_age::seconds()) / YEAR_IN_SECONDS);
}

double space_age::on_mercury() const
{
    return (space_age::on_earth() / MERCURY_PERIOD);
}

double space_age::on_venus() const
{
    return (space_age::on_earth() / VENUS_PERIOD);
}

double space_age::on_mars() const
{
    return (space_age::on_earth() / MARS_PERIOD);
}

double space_age::on_jupiter() const
{
    return (space_age::on_earth() / JUPITER_PERIOD);
}

double space_age::on_saturn() const
{
    return (space_age::on_earth() / SATURN_PERIOD);
}

double space_age::on_uranus() const
{
    return (space_age::on_earth() / URANUS_PERIOD);
}
    
double space_age::on_neptune() const
{
    return (space_age::on_earth() / NEPTUNE_PERIOD);
}

}  // namespace space_age
