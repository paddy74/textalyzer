#pragma once

#include <string>
#include <vector>


namespace textalyzer
{

/**
 * @brief Construct ngrams for the given ordered token vector.
 *
 * @param tokenVect Ordered token vector from which to construct ngrams.
 * @param n Size of max ngram. All lesser ngrams are also collected.
 * @return std::vector<std::string>
 */
std::vector<std::string> ngramify(
    std::vector<std::string> const & tokenVect,
    uint const & n
)
{
    // TODO: infinite grams (recursive)
    std::vector<std::string> ngramVect;
    for (
        auto tokenItr = tokenVect.begin();
        tokenItr < tokenVect.end()-1;
        ++tokenItr)
    {
        // 1-gram
        ngramVect.push_back(*tokenItr);

        // 2-gram
        if (n >= 2)
        {
            auto const & next1 = tokenItr + 1;
            if (next1 != tokenVect.end())
                ngramVect.push_back(*tokenItr + ' ' + *next1);

            // 3-gram
            if (n >= 3)
            {
                auto const & next2 = next1 + 1;
                if (next2 != tokenVect.end())
                    ngramVect.push_back(*tokenItr + ' ' + *next1 + ' ' + *next2);
            }
        }
    }

    return ngramVect;
}


/**
 * @brief Construct ngrams for the given ordered token vector inplace.
 *
 * @param tokenVect Ordered token vector from which to construct ngrams.
 * @param n Size of max ngram. All lesser ngrams are also collected.
 */
void ngramifyInplace(
    std::vector<std::string> & tokenVect,
    uint const & n
)
{ tokenVect = ngramify(tokenVect, n); }

}
