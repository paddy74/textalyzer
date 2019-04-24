#pragma once

#include <string>
#include <vector>
#include <functional>


namespace textalyzer
{

typedef std::pair<std::vector<std::string>, std::size_t> AnlyzedTextType;

typedef std::function<AnlyzedTextType(std::string, uint8_t)> AnlyzerFunType;


/**
 * @brief Create a vector of analyzed tokens using the following methods:
 *
 * @param inputText
 * @param ngrams
 * @return std::pair<std::vector<std::string>, std::size_t>
 */
std::pair<std::vector<std::string>, std::size_t> simpleAnalyze(
    std::string const & inputText, uint8_t const & ngrams);


/**
 * @brief Create a vector of analyzed tokens using the following methods:
 *
 * @param inputText
 * @return std::pair<std::vector<std::string>, std::size_t>
 */
std::pair<std::vector<std::string>, std::size_t> simpleAnalyze(
    std::string const & inputText
) { return simpleAnalyze(inputText, 2); };


/**
 * @brief Create a vector of analyzed tokens using the following methods:
 *
 * @param inputText
 * @param ngrams
 * @return std::pair<std::vector<std::string>, std::size_t>
 */
std::pair<std::vector<std::string>, std::size_t> static fullAnalyze(
    std::string const & inputText, uint8_t const & ngrams);


/**
 * @brief Create a vector of analyzed tokens using the following methods:
 *
 * @param inputText
 * @return std::pair<std::vector<std::string>, std::size_t>
 */
std::pair<std::vector<std::string>, std::size_t> static fullAnalyze(
    std::string const & inputText
) { return fullAnalyze(inputText, 2); }

}
