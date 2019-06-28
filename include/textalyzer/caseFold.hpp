#pragma once

#include <string>

namespace textalyzer
{
/**
 * @brief Transform every character in a string to lower case inplace.
 *
 * @param str
 */
void toLower(std::string & str);

/**
 * @brief Transform every character in a string to lower case and return a
 * copy.
 *
 * @param str
 * @return std::string
 */
std::string asLower(std::string const & str);

/**
 * @brief Transform every character in a string to upper case inplace.
 *
 * @param str
 */
void toUpper(std::string & str);

/**
 * @brief Transform every character in a string to upper case and return a
 * copy.
 *
 * @param str
 * @return std::string
 */
std::string asUpper(std::string const & str);

}  // namespace textalyzer
