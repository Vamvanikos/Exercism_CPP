#include "bob.h"
#include <cctype>
#include <algorithm>

namespace bob {

void remove_whitespace(std::string& sentence)
{
    auto not_space = [](char ch) { return !std::isspace(static_cast<unsigned char>(ch)); };
    sentence.erase(sentence.begin(),
            std::find_if(sentence.begin(), sentence.end(), not_space));
    sentence.erase(std::find_if(sentence.rbegin(), sentence.rend(), not_space).base(), sentence.end());
}

bool has_questionmark(const std::string& sentence)
{
    if (!sentence.empty())
        return sentence.back() == '?';

    return false;
}
    
bool has_caps(const std::string& sentence)
{
    return std::any_of(sentence.begin(), sentence.end(),
        [](unsigned char ch) { return std::isupper(ch);});
}

bool has_lowcase(const std::string& sentence)
{
    return std::any_of(sentence.begin(), sentence.end(),
        [](unsigned char ch) { return std::islower(ch);});
}
    
std::string hey(const std::string& sentence)
{
    std::string analyzedSentence = sentence;
    remove_whitespace(analyzedSentence);
    if (analyzedSentence.empty())
        return "Fine. Be that way!";
    
    bool questmark = has_questionmark(analyzedSentence);
    bool hasCaps = has_caps(analyzedSentence);
    bool hasLowcase = has_lowcase(analyzedSentence);
    if (hasCaps && !hasLowcase)
    {
        return questmark ? "Calm down, I know what I'm doing!" :
                           "Whoa, chill out!";
    }
    if (questmark)
        return "Sure.";
    
    return "Whatever.";
}

}  // namespace bob
