#pragma once

#include <regex>

namespace textalyzer
{
/**
 * @brief Replace all instances of the given substring with a new substring.
 *  Acts inplace.
 * @param str
 * @param subString
 * @param newSubString
 * @return std::string
 */
void replaceSubstr(
    std::string & str, std::string const & subString,
    std::string const & newSubString)
{
    std::regex pattern(subString);
    std::regex_replace(str, pattern, newSubString);
}

/**
 * @brief Remove all instances of the given substring inplace.
 *
 * @param str
 * @param subString
 * @return std::string
 */
void removeSubstr(std::string & str, std::string const & subString)
{
    replaceSubstr(str, subString, "");
}

/**
 * @brief Remove all non-alphanumeric non-whitespace characters from a string.
 *  Acts inplace.
 *
 * @param str
 */
void removeNotAlnum(std::string & str)
{
    auto static isNotAlNumSpace = [](char const & c) {
        return !(std::isspace(c) || std::isalnum(c));
    };

    str.erase(
        std::remove_if(str.begin(), str.end(), isNotAlNumSpace), str.end());
}

/**
 * @brief Remove all non-alphanumeric non-whitespace characters from a string.
 *
 * @param str
 */
std::string removeNotAlnumCopy(std::string const & str)
{
    std::string outStr = str;
    removeNotAlnum(outStr);
    return outStr;
}

/**
 * @brief Remove all non-alphabetic non-whitespace characters from a string.
 *  Acts inplace.
 *
 * @param str
 * @return std::string
 */
void removeNotAlpha(std::string & str)
{
    auto static isNotAlphaSpace = [](char const & c) {
        return !(std::isspace(c) || std::isalpha(c));
    };

    str.erase(
        std::remove_if(str.begin(), str.end(), isNotAlphaSpace), str.end());
}

/**
 * @brief Remove all non-alphabetic non-whitespace characters from a string.
 *
 * @param str
 * @return std::string
 */
std::string removeNotAlphaCopy(std::string const & str)
{
    std::string outStr = str;
    removeNotAlpha(outStr);
    return outStr;
}

}  // namespace textalyzer
