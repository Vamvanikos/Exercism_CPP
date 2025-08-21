#include "binary_search.h"
#include <algorithm>
#include <stdexcept>

namespace binary_search {

// TODO: add your solution here
std::size_t find(std::vector<int> intSongList, int song)
{
    std::size_t low = 0;
    std::size_t high = intSongList.size();

    if (intSongList.empty())
        throw std::domain_error("List is empty.");

    std::sort(intSongList.begin(), intSongList.end()); 
    while (low < high)
    {
        std::size_t mid = low + (high - low)/2;
        if (song == intSongList[mid])
            return mid;
        else if (song > intSongList[mid])
            low = mid + 1;
        else
            high = mid;
    }

    throw std::domain_error("Song does not exist in list");
}

}  // namespace binary_search
