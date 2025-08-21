#pragma once
#include <list>

namespace sublist {

enum class List_comparison {
    equal,
    sublist,
    superlist,
    unequal
};

List_comparison sublist(const std::list<int>& list1, const std::list<int>& list2);

}  // namespace sublist
