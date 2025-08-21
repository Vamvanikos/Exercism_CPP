#include "pangram.h"
#include <algorithm>

namespace pangram {

bool is_pangram(const std::string& sentence)
{
    if (sentence.size() < ALPHA_SIZE)
        return false;

    std::string converted = sentence;
    std::transform(converted.begin(), converted.end(), converted.begin(), [] (unsigned char ch) {
        return std::tolower(ch);
    });
    
    for (char ch = 'a'; ch <= 'z'; ++ch)
    {
        // transform + find() solution costs more than needed.
        if (converted.find(ch) == std::string::npos)
            return false;
    }
    
    return true;
}

}  // namespace pangram
