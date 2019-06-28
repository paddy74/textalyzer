#include <regex>
#include <textalyzer/editCharacter.hpp>

namespace textalyzer
{
void replaceSubstr(
    std::string & str, std::string const & subString,
    std::string const & newSubString)
{
    std::regex pattern(subString);
    std::regex_replace(str, pattern, newSubString);
}

void removeSubstr(std::string & str, std::string const & subString)
{
    replaceSubstr(str, subString, "");
}

void removeNotAlnum(std::string & str)
{
    auto static isNotAlNumSpace = [](char const & c) {
        return !(std::isspace(c) || std::isalnum(c));
    };

    str.erase(
        std::remove_if(str.begin(), str.end(), isNotAlNumSpace), str.end());
}

std::string removeNotAlnumCopy(std::string const & str)
{
    std::string outStr = str;
    removeNotAlnum(outStr);
    return outStr;
}

void removeNotAlpha(std::string & str)
{
    auto static isNotAlphaSpace = [](char const & c) {
        return !(std::isspace(c) || std::isalpha(c));
    };

    str.erase(
        std::remove_if(str.begin(), str.end(), isNotAlphaSpace), str.end());
}

std::string removeNotAlphaCopy(std::string const & str)
{
    std::string outStr = str;
    removeNotAlpha(outStr);
    return outStr;
}

}  // namespace textalyzer
