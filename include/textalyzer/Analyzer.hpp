#pragma once

#include <functional>
#include <string>
#include <vector>

namespace textalyzer
{
template <typename T>
using AnlyzerRetType = std::pair<std::vector<T>, std::size_t>;

template <typename A>
using AnlyzerFunType =
    std::function<AnlyzerRetType<A>(std::string const &, uint8_t const &)>;

class Analyzer
{
public:
    /* Public static member variables */

    uint8_t static const DEFAULT_NGRAMS;
    uint8_t static const DEFAULT_DEMBEDDINGS;

    /* Public static class methods */

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
    AnlyzerRetType<std::string> static lowAnalyze(
        std::string const & inputText, uint8_t const & ngrams);

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
    AnlyzerRetType<std::string> static medAnalyze(
        std::string const & inputText, uint8_t const & ngrams);

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
    AnlyzerRetType<std::vector<std::string>> static highAnalyze(
        std::string const & inputText, uint8_t const & dembeddings);

private:
    Analyzer() {}
};

}  // namespace textalyzer
