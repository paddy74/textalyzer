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
std::vector<std::string> strSplit(std::string const & str, char const & delim)
{
    std::vector<std::string> tokens;

    // Skip delimiters at the beginning
    std::string::size_type lastPos = str.find_first_not_of(delim, 0);
    // Find first non-delimiter
    std::string::size_type pos = str.find_first_of(delim, lastPos);

    while ((std::string::npos != pos || std::string::npos != lastPos))
    {
        // Found token, add to the token vector
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters
        lastPos = str.find_first_not_of(delim, pos);
        // Find next non-delimiter
        pos = str.find_first_of(delim, lastPos);
    }

    return tokens;
}

/**
 * @brief Split a string on a character delimiter.
 *
 * @param str
 * @param delim
 * @return std::vector<std::string>
 */
std::vector<std::string> strSplit(
    std::string const & str, std::string const & delim)
{
    std::vector<std::string> tokens;

    // Skip delimiters at the beginning
    std::string::size_type lastPos = str.find_first_not_of(delim, 0);
    // Find first non-delimiter
    std::string::size_type pos = str.find_first_of(delim, lastPos);

    while ((std::string::npos != pos || std::string::npos != lastPos))
    {
        // Found token, add to the token vector
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters
        lastPos = str.find_first_not_of(delim, pos);
        // Find next non-delimiter
        pos = str.find_first_of(delim, lastPos);
    }

    return tokens;
}

/**
 * @brief Split a string into a vector of words.
 *
 * @param str
 * @return std::vector<std::string>
 */
std::vector<std::string> tokenizeByWord(std::string const & str)
{
    return strSplit(str, ' ');
}

/**
 * @brief Split a string into a vector of sentences.
 *
 * @param str
 * @return std::vector<std::string>
 */
std::vector<std::string> tokenizeBySentence(std::string const & str)
{
    std::string static const fullStopChars = ".!?";
    return strSplit(str, fullStopChars);
}

/**
 * @brief Split a string into a vector of paragraphs.
 *
 * @param str
 * @return std::vector<std::string>
 */
std::vector<std::string> tokenizeByParagraph(std::string const & str)
{
    return strSplit(str, '\n');
}

}  // namespace textalyzer
