#include <string>
#include <textalyzer/editCharacter.hpp>
#include <textalyzer/ngramify.hpp>
#include <textalyzer/tokenize.hpp>
#include <vector>

namespace textalyzer
{
std::vector<std::string> ngramify(
    std::vector<std::string> const & wordVect, uint const & n)
{
    if (n <= 1) return wordVect;
    if (wordVect.size() == 0) return wordVect;

    std::vector<std::string> outNgramVect;
    for (auto tokenItr = wordVect.begin(); tokenItr < wordVect.end() - 1;
         ++tokenItr)
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

std::vector<std::string> ngramify(std::string const & str, uint8_t const & n)
{
    if (n <= 1) return tokenizeByWord(str);
    if (str == "") return std::vector<std::string>();

    std::vector<std::string> sentenceCommaVect = strSplit(str, ",.!?");
    if (sentenceCommaVect.size() <= 1) return sentenceCommaVect;

    std::vector<std::string> outNgramVect;
    for (auto & sentence : sentenceCommaVect)
    {
        removeNotAlpha(sentence);
        std::vector<std::string> wordVect = tokenizeByWord(sentence);

        for (auto tokenItr = wordVect.begin(); tokenItr < wordVect.end() - 1;
             ++tokenItr)
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
                        outNgramVect.push_back(
                            *tokenItr + ' ' + *next1 + ' ' + *next2);
                }
            }
        }
    }

    return outNgramVect;
}

void ngramifyInplace(std::vector<std::string> & wordVect, uint const & n)
{
    wordVect = ngramify(wordVect, n);
}

}  // namespace textalyzer
