#include "allergies.h"

namespace allergies {

// TODO: add your solution here
    allergy_test::allergy_test(const unsigned int& score)
    {
        m_score = score;
    }

    bool allergy_test::is_allergic_to(const std::string& item)
    {
        bool ret = false;
        for (const auto& allergy_item : allergy_items)
            {
                if ((item == allergy_item.first) &&
                    (m_score & allergy_item.second))
                {
                    ret = true;
                    break;
                }
            }

        return ret;
    }

    std::unordered_set<std::string> allergy_test::get_allergies()
    {
        std::unordered_set<std::string> allergies;
        for (const auto& allergy_item : allergy_items)
            {
                if (m_score & allergy_item.second)
                {
                    allergies.emplace(allergy_item.first);
                }
            }

        return allergies;
    }
}  // namespace allergies
