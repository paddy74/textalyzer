#pragma once

#include <string>
#include <vector>
#include <functional>


namespace textalyzer
{

template<typename T>
using AnlyzerRetType = std::pair<std::vector<T>, std::size_t>;

template<typename A>
using AnlyzerFunType = std::function<AnlyzerRetType<A>(std::string, uint8_t);


/* Low level analyzer */

/**
 * @brief Create a vector of analyzed tokens using the following methods:
 *  1. Case fold to lower case
 *  2. Remove non-alphabetic non-space characters
 *  3. Tokenize words
 *  4. Construct n-grams
 *
 * @param inputText
 * @param ngrams
 * @return AnlyzerRetType<std::string>
 */
AnlyzerRetType<std::string> lowAnalyze(
    std::string const & inputText, uint8_t const & ngrams);


/**
 * @brief Create a vector of analyzed tokens using the following methods:
 *  1. Case fold to lower case
 *  2. Remove non-alphabetic non-space characters
 *  3. Tokenize words
 *  4. Construct n-grams
 *
 * @param inputText
 * @return AnlyzerRetType<std::string>
 */
AnlyzerRetType<std::string> lowAnalyze(
    std::string const & inputText
) { return lowAnalyze(inputText, 2); };


/* Medium level analyzer */

/**
 * @brief Create a vector of analyzed tokens using the following methods:
 *  1. Case fold to lower case
 *  2. Remove non-alphabetic non-space characters
 *  3. Tokenize words
 *  4. Remove stop words
 *  5. Reduce words to their base form with porter stemming
 *  6. Construct n-grams
 *
 * @param inputText
 * @param ngrams
 * @return AnlyzerRetType<std::string>
 */
AnlyzerRetType<std::string> medAnalyze(
    std::string const & inputText, uint8_t const & ngrams);


/**
 * @brief Create a vector of analyzed tokens using the following methods:
 *  1. Case fold to lower case
 *  2. Remove non-alphabetic non-space characters
 *  3. Tokenize words
 *  4. Remove stop words
 *  5. Reduce words to their base form with porter stemming
 *  6. Construct n-grams
 *
 * @param inputText
 * @return AnlyzerRetType<std::string>
 */
AnlyzerRetType<std::string> medAnalyze(
    std::string const & inputText
) { return medAnalyze(inputText, 2); }


/* High level analyzer */

/**
 * @brief Create a vector of analyzed tokens using the following methods:
 *  1. Case fold to lower case
 *  2. Remove non-alphabetic non-space characters
 *  3. Tokenize words
 *  4. TODO: Construct n-grams
 *  5. Construct words embeddings
 *
 * @param inputText
 * @param dembeddings
 * @return AnlyzerRetType<std::vector<std::string>>
 */
AnlyzerRetType<std::vector<std::string>> highAnalyze(
    std::string const & inputText, uint8_t const & dembeddings);


/**
 * @brief Create a vector of analyzed tokens using the following methods:
 *
 * @param inputText
 * @return AnlyzerRetType<std::vector<std::string>>
 */
AnlyzerRetType<std::vector<std::string>> highAnalyze(
    std::string const & inputText
) { return highAnalyze(inputText, 0); };

}
