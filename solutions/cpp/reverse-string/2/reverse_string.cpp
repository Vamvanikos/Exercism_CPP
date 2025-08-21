#include "reverse_string.h"
//#include <algorithm>

namespace reverse_string {

std::string reverse_string(std::string word)
{
    for (size_t i = 0; i < word.size() / 2; ++i)
    {
        char tmp = word[i];
        word[i] = word[word.size() - 1 - i];
        word[word.size() - 1 - i] = tmp;
    }
    //std::reverse(word.begin(), word.end());

    return word;
}

}  // namespace reverse_string
