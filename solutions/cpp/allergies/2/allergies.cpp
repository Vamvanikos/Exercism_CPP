#include "allergies.h"
#include <stdexcept>

namespace allergies {

std::unordered_set<std::string> allergy_test::get_allergies() const
{
    std::unordered_set<std::string> allergies;
    allergies.reserve(allergyItems.size());
    for (const auto& [allergy, value] : allergyItems)
        if (m_allergyScore & value)
            allergies.emplace(allergy);

    return allergies;
}
    
bool allergy_test::is_allergic_to(const std::string& allergy) const
{
    auto it = allergyItems.find(allergy);
    if (it == allergyItems.end())
        throw std::invalid_argument("Inserted allergy does not exist. Please provide valid allergy.");

    return m_allergyScore & it->second;
}

}  // namespace allergies
