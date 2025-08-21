#include "space_age.h"

namespace space_age {

long space_age::seconds() const
{
    return secs;
}

double space_age::on_earth() const
{
    return static_cast<double>(space_age::seconds()) / YEAR_IN_SECONDS;
}

double space_age::on_planet(double period) const 
{
    return space_age::on_earth() / period;
}

double space_age::on_mercury() const
{
    return on_planet(MERCURY_PERIOD);
}

double space_age::on_venus() const
{
    return on_planet(VENUS_PERIOD);
}

double space_age::on_mars() const
{
    return on_planet(MARS_PERIOD);
}

double space_age::on_jupiter() const
{
    return on_planet(JUPITER_PERIOD);
}

double space_age::on_saturn() const
{
    return on_planet(SATURN_PERIOD);
}

double space_age::on_uranus() const
{
    return on_planet(URANUS_PERIOD);
}
    
double space_age::on_neptune() const
{
    return on_planet(NEPTUNE_PERIOD);
}

}  // namespace space_age
