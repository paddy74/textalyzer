#pragma once

#include <regex>


namespace textalyzer
{

/**
 * @brief Replace all instances of the given substring with a new substring.
 *
 * @param str
 * @param subString
 * @param newSubString
 * @return std::string
 */
void replaceSubstr(
    std::string & str, std::string const & subString,
    std::string const & newSubString
)
{
    std::regex pattern(subString);
    std::regex_replace(str, pattern, newSubString);
}


/**
 * @brief Remove all instances of the given substring.
 *
 * @param str
 * @param subString
 * @return std::string
 */
void removeSubstr(std::string & str, std::string const & subString)
{ replaceSubstr(str, subString, ""); }


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
        tokens.push_back(str.substr(lastPos, pos-lastPos));
        // Skip delimiters
        lastPos = str.find_first_not_of(delim, pos);
        // Find next non-delimiter
        pos = str.find_first_of(delim, lastPos);
    }

    return tokens;
}


/**
 * @brief Split a string on spaces
 *
 * @param str
 * @return std::vector<std::string>
 */
std::vector<std::string> strSplit(std::string const & str)
{ return strSplit(str, ' '); }


/**
 * @brief Transform every character in a string to lower case inplace.
 *
 * @param str
 */
void toLowerInplace(std::string & str)
{ std::transform(str.begin(), str.end(), str.begin(), ::tolower); }


/**
 * @brief Transfor every character in a string to lower case and return a copy.
 *
 * @param str
 * @return std::string
 */
std::string toLowerCopy(std::string const & str)
{
    std::string outStr = str;
    toLowerInplace(outStr);
    return outStr;
}


/**
 * @brief Transform every character in a string to upper case inplace.
 *
 * @param str
 */
void toUpperInplace(std::string & str)
{ std::transform(str.begin(), str.end(), str.begin(), ::toupper); }


/**
 * @brief Transform every character in a string to upper case and return a copy.
 *
 * @param str
 * @return std::string
 */
std::string toUpperCopy(std::string const & str)
{
    std::string outStr = str;
    toUpperInplace(outStr);
    return outStr;
}


/**
 * @brief Identifies if a character is not alphnumeric.
 *
 * @param c
 * @return true Character is not alphanumeric.
 * @return false Character is alphanumeric.
 */
bool isNotAlNum(char const & c)
{ return !std::isalnum(c); }


/**
 * @brief Remove all non-alphanumeric characters from a string.
 *
 * @param str
 */
void rmNonAlNumInplace(std::string & str)
{
    str.erase(
        std::remove_if(
            str.begin(),
            str.end(),
            isNotAlNum
        ),
        str.end()
    );
}


/**
 * @brief Identifies if a character is not alphanumeric or whitespace.
 *
 * @param c
 * @return true Character is not alphanumeric or whitespace.
 * @return false Character is alphnumeric or whitespace.
 */
bool isNotAlNumSpace(char const & c)
{ return !(std::isalnum(c) || std::isspace(c); }


/**
 * @brief Remove all non-alphanumeric non-whitespace characters from a string.
 *
 * @param str
 */
void rmNonAlNumSpaceInplace(std::string & str)
{
    str.erase(
        std::remove_if(
            str.begin(),
            str.end(),
            isNotAlNumSpace
        ),
        str.end()
    );
}

std::string rmNonAlNumSpaceCopy(std::string const & str)
{
    std::string outStr = str;
    rmNonAlNumSpaceInplace(outStr);
    return outStr;
}


std::string rmNonAlphaSpace(std::string & str)
{
    auto static isNotAlphaSpace = [](char const & c)
    { return !(std::isspace(c) || std::isalpha(c)); };

    str.erase(
        std::remove_if(
            str.begin(),
            str.end(),
            isNotAlphaSpace
        ),
        str.end()
    );
}

}
