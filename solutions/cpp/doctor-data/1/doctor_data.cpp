#include "doctor_data.h"

heaven::Vessel::Vessel(std::string inputName, int gen) : Vessel(inputName, gen, star_map::System::Sol) {}

heaven::Vessel::Vessel(std::string inputName, int gen, star_map::System starStuff) : name(std::move(inputName)), generation(gen), busters(0), current_system(starStuff) {}

heaven::Vessel heaven::Vessel::replicate(std::string inputName)
{
    Vessel rep(inputName, ++generation);

    return rep;
}

void heaven::Vessel::make_buster()
{
    busters++;
}

bool heaven::Vessel::shoot_buster()
{
    return busters--;
}

std::string heaven::get_older_bob(Vessel name1, Vessel name2)
{
    return (name1.generation < name2.generation) ? name1.name : name2.name;
}

bool heaven::in_the_same_system(Vessel name1, Vessel name2)
{
    return (name1.current_system == name2.current_system);
}