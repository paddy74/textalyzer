#pragma once

#include <string>
#include <textalyzer/editCharacter.hpp>
#include <textalyzer/tokenize.hpp>
#include <vector>

namespace textalyzer
{
/**
 * @brief Construct n-grams for the given ordered token vector.
 *  // TODO: Recursive n-gram cound.
 *
 * @param wordVect Ordered token vector from which to construct ngrams.
 * @param n Size of max n-gram. All lesser n-grams are also collected.
 * @return std::vector<std::string>
 */
std::vector<std::string> ngramify(
    std::vector<std::string> const & wordVect, uint const & n);

/**
 * @brief Splits a string into n-ngrams. Considers punctuation, etc.
 *  // TODO: Recursive n-gram count.
 *
 * @param str
 * @param n
 * @return std::vector<std::string>
 */
std::vector<std::string> ngramify(std::string const & str, uint8_t const & n);

/**
 * @brief Construct n-grams for the given ordered token vector inplace.
 *
 * @param wordVect Ordered token vector from which to construct n-grams.
 * @param n Size of max ngram. All lesser n-grams are also collected.
 */
void ngramifyInplace(std::vector<std::string> & wordVect, uint const & n);

}  // namespace textalyzer
