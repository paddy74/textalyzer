#pragma once

#include <string>
#include <vector>

namespace textalyzer
{
/**
 * @brief Split a string on a character delimiter.
 *
 * @param str
 * @param delim
 * @return std::vector<std::string>
 */
std::vector<std::string> strSplit(std::string const & str, char const & delim);

/**
 * @brief Split a string on a character delimiter.
 *
 * @param str
 * @param delim
 * @return std::vector<std::string>
 */
std::vector<std::string> strSplit(
    std::string const & str, std::string const & delim);

/**
 * @brief Split a string into a vector of words.
 *
 * @param str
 * @return std::vector<std::string>
 */
std::vector<std::string> tokenizeByWord(std::string const & str);

/**
 * @brief Split a string into a vector of sentences.
 *
 * @param str
 * @return std::vector<std::string>
 */
std::vector<std::string> tokenizeBySentence(std::string const & str);

/**
 * @brief Split a string into a vector of paragraphs.
 *
 * @param str
 * @return std::vector<std::string>
 */
std::vector<std::string> tokenizeByParagraph(std::string const & str);

}  // namespace textalyzer
