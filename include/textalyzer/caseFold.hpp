#pragma once

#include <algorithm>
#include <string>

namespace textalyzer
{
/**
 * @brief Transform every character in a string to lower case inplace.
 *
 * @param str
 */
void toLower(std::string & str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

/**
 * @brief Transform every character in a string to lower case and return a copy.
 *
 * @param str
 * @return std::string
 */
std::string asLower(std::string const & str)
{
    std::string outStr = str;
    toLower(outStr);
    return outStr;
}

/**
 * @brief Transform every character in a string to upper case inplace.
 *
 * @param str
 */
void toUpper(std::string & str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

/**
 * @brief Transform every character in a string to upper case and return a copy.
 *
 * @param str
 * @return std::string
 */
std::string asUpper(std::string const & str)
{
    std::string outStr = str;
    toUpper(outStr);
    return outStr;
}

}  // namespace textalyzer
