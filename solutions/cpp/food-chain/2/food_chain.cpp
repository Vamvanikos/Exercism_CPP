#include "food_chain.h"

namespace food_chain {

namespace {
    inline constexpr int FIRST_VERSE = 1;
    inline constexpr int SECOND_VERSE = 2;
    inline constexpr int LAST_VERSE = 8;
    inline constexpr int BEINGS_NUM = 8;
    inline constexpr int BEINGS_COMMENT = 7;
    
    const std::array<std::string, BEINGS_NUM> beings = {
        "fly", "spider", "bird", "cat",
        "dog", "goat", "cow", "horse"
    };
    
    const std::array<std::string, BEINGS_COMMENT> comment = {
        "It wriggled and jiggled and tickled inside her.\n",
        "How absurd to swallow a bird!\n",
        "Imagine that, to swallow a cat!\n",
        "What a hog, to swallow a dog!\n",
        "Just opened her throat and swallowed a goat!\n",
        "I don't know how she swallowed a cow!\n"
    };
}

std::string swallow_verse(int index)
{
    if (index < FIRST_VERSE)
        return "";

    std::string line = "She swallowed the " + beings[index] +
                       " to catch the " + beings[index - 1] +
                       (index == SECOND_VERSE
                       ? " that wriggled and jiggled and tickled inside her.\n"
                       : ".\n" );

    return line + swallow_verse(index - 1);
}

std::string verse(int num)
{
    if (num < FIRST_VERSE || num > LAST_VERSE)
        return "";

    std::string retVerse = "I know an old lady who swallowed a " + 
                            beings[num - 1] + ".\n";

    if (num == LAST_VERSE)
        retVerse += "She's dead, of course!\n";
    else
    {
        if (num != FIRST_VERSE)
        {
            retVerse += comment[num - 2];
            retVerse += swallow_verse(num - 1);
        }
        retVerse += "I don't know why she swallowed the fly. Perhaps she'll die.\n";
    }

    return retVerse;
}

std::string verses(int start, int end)
{
    std::string retVerses;
    for (int i = start; i <= end; ++i)
    {
        retVerses += verse(i) + "\n";
    }

    return retVerses;
}

std::string sing()
{
    return verses(FIRST_VERSE, LAST_VERSE);
}

}  // namespace food_chain
