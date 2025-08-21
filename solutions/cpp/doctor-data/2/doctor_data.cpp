#include "doctor_data.h"

namespace heaven{

Vessel Vessel::replicate(std::string n) const
{
    return Vessel(std::move(n), generation + 1, current_system);
}

void Vessel::make_buster()
{
    ++busters;
}

bool Vessel::shoot_buster()
{
    if (busters == 0)
        return false;
    --busters;

    return true;
}

std::string get_older_bob(const Vessel& v1, const Vessel& v2)
{
    return (v1.generation < v2.generation) ? v1.name : v2.name;
}
bool in_the_same_system(const Vessel& v1, const Vessel& v2)
{
    return v1.current_system == v2.current_system;
}

}