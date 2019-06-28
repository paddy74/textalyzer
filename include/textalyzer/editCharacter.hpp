#pragma once

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
    std::string const & newSubString);

/**
 * @brief Remove all instances of the given substring inplace.
 *
 * @param str
 * @param subString
 * @return std::string
 */
void removeSubstr(std::string & str, std::string const & subString);

/**
 * @brief Remove all non-alphanumeric non-whitespace characters from a string.
 *  Acts inplace.
 *
 * @param str
 */
void removeNotAlnum(std::string & str);

/**
 * @brief Remove all non-alphanumeric non-whitespace characters from a string.
 *
 * @param str
 */
std::string removeNotAlnumCopy(std::string const & str);

/**
 * @brief Remove all non-alphabetic non-whitespace characters from a string.
 *  Acts inplace.
 *
 * @param str
 * @return std::string
 */
void removeNotAlpha(std::string & str);

/**
 * @brief Remove all non-alphabetic non-whitespace characters from a string.
 *
 * @param str
 * @return std::string
 */
std::string removeNotAlphaCopy(std::string const & str);

}  // namespace textalyzer
