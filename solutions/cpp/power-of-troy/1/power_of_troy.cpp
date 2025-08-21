#include "power_of_troy.h"

namespace troy {

void give_new_artifact(human& person, const std::string& artifactName)
{
    person.possession = std::make_unique<artifact>(artifactName);
}

void exchange_artifacts(std::unique_ptr<artifact>& item1, std::unique_ptr<artifact>& item2)
{
    std::swap(item1, item2);
}

void manifest_power(human& person, const std::string& newPower)
{
    person.own_power = std::make_shared<power>(newPower);
}

void use_power(const human& caster, human& target)
{
    target.influenced_by = caster.own_power;
}

int power_intensity(const human& person)
{
    return (person.own_power ? static_cast<int>(person.own_power.use_count()) : 0);
}
    
}  // namespace troy
