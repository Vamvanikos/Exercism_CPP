#include "sublist.h"

namespace sublist {

bool is_sublist(const std::list<int>& small, const std::list<int>& big)
{
    if (small.size() > big.size())
        return false;
    if (small.empty())
        return true;
    
    const auto bigEnd = big.end();
    const auto smallIt = small.begin();
    const auto smallEnd = small.end();
    for (auto bigIt = big.begin(); bigIt != bigEnd; ++bigIt)
    {
        auto b = bigIt;
        auto s = smallIt;

        while (s != smallEnd && *s == *b)
        {
            ++s;
            ++b;
        }
        if (s == smallEnd)
            return true;
    }
    
    return false;
}

List_comparison sublist(const std::list<int>& list1, const std::list<int>& list2)
{
    if (list1 == list2)
        return List_comparison::equal;
    if (is_sublist(list1, list2))
        return List_comparison::sublist;
    if (is_sublist(list2, list1))
        return List_comparison::superlist;
    return List_comparison::unequal;
}

}  // namespace sublist