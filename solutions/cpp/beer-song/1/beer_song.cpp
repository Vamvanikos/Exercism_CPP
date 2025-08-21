#include "beer_song.h"

namespace beer_song {

// TODO: add your solution here
std::string verse(int ver)
{
    std::string numOfBottles, verseString2;
    if (ver == 0)
    {
        numOfBottles = "No more bottles";
        verseString2 = "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
    }
    else if (ver == 1)
    {
        numOfBottles = "1 bottle";
        verseString2 = "Take it down and pass it around, no more bottles of beer on the wall.\n";
    }
    else
    {
        numOfBottles = std::to_string(ver) + " bottles";
        verseString2 = "Take one down and pass it around, ";
        if (ver == 2) verseString2 += std::to_string(ver - 1) + " bottle";
        else verseString2 += std::to_string(ver - 1) + " bottles";
        verseString2 += " of beer on the wall.\n";
    }
    
    std::string verseString1 = numOfBottles + " of beer on the wall, ";
    numOfBottles[0] = std::tolower(numOfBottles[0]);
    verseString1 += numOfBottles + " of beer.\n";

    return (verseString1 + verseString2);
}

std::string sing(int startVerse, int endVerse)
{
    std::string song;
    for (int i = startVerse; i >= endVerse; --i)
    {
        song += verse(i) + "\n";
    }
    song.pop_back();

    return song;
}

}  // namespace beer_song
