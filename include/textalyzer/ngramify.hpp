#pragma once

#include <textalyzer/tokenize.hpp>
#include <textalyzer/editCharacter.hpp>

#include <string>
#include <vector>


namespace textalyzer
{

/**
 * @brief Construct n-grams for the given ordered token vector.
 *
 * @param wordVect Ordered token vector from which to construct ngrams.
 * @param n Size of max n-gram. All lesser n-grams are also collected.
 * @return std::vector<std::string>
 */
std::vector<std::string> ngramify(
    std::vector<std::string> const & wordVect,
    uint const & n
)
{
    if (n <= 1) return wordVect;

    // TODO: Infinite grams (recursive)
    // TODO: Don't n-gram on period
    std::vector<std::string> outNgramVect;
    for (
        auto tokenItr = wordVect.begin();
        tokenItr < wordVect.end()-1;
        ++tokenItr
    )
    {
        // 1-gram
        outNgramVect.push_back(*tokenItr);

        // 2-gram
        if (n >= 2)
        {
            auto const & next1 = tokenItr + 1;
            if (next1 != wordVect.end())
                outNgramVect.push_back(*tokenItr + ' ' + *next1);

            // 3-gram
            if (n >= 3)
            {
                auto const & next2 = next1 + 1;
                if (next2 != wordVect.end())
                {
                    outNgramVect.push_back(
                        *tokenItr + ' ' + *next1 + ' ' + *next2);
                }
            }
        }
    }

    return outNgramVect;
}


/**
 * @brief Splits a string into n-ngrams. Considers punctuation, etc.
 *
 * @param str
 * @param n
 * @return std::vector<std::string>
 */
std::vector<std::string> ngramify(
    std::string const & str,
    uint8_t const & n
)
{
    if (n <= 1) return tokenizeByWord(str);

    std::vector<std::string> outNgramVect;
    std::vector<std::string> sentenceCommaVect = strSplit(str, ",.!?");
    for (auto & sentence : sentenceCommaVect)
    {
        removeNotAlpha(sentence);
        std::vector<std::string> wordVect = tokenizeByWord(sentence);

        for (
            auto tokenItr = wordVect.begin();
            tokenItr < wordVect.end()-1;
            ++tokenItr
        )
        {
            // 1-gram
            outNgramVect.push_back(*tokenItr);

            // 2-gram
            if (n >= 2)
            {
                auto const & next1 = tokenItr + 1;
                if (next1 != wordVect.end())
                    outNgramVect.push_back(*tokenItr + ' ' + *next1);

                // 3-gram
                if (n >= 3)
                {
                    auto const & next2 = next1 + 1;
                    if (next2 != wordVect.end())
                        outNgramVect.push_back(*tokenItr + ' ' + *next1 + ' ' + *next2);
                }
            }
        }
    }

    return outNgramVect;
}


/**
 * @brief Construct n-grams for the given ordered token vector inplace.
 *
 * @param wordVect Ordered token vector from which to construct n-grams.
 * @param n Size of max ngram. All lesser n-grams are also collected.
 */
void ngramifyInplace(
    std::vector<std::string> & wordVect,
    uint const & n
)
{ wordVect = ngramify(wordVect, n); }

}
