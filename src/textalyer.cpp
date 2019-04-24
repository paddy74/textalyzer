#include <textalyzer/textalyzer.hpp>

#include <textalyzer/caseFold.hpp>
#include <textalyzer/editCharacter.hpp>
#include <textalyzer/tokenize.hpp>
#include <textalyzer/WordFilter.hpp>
#include <textalyzer/ngramify.hpp>

#include <olestem/stemming/english_stem.h>

#include <codecvt>


namespace textalyzer
{

std::pair<std::vector<std::string>, std::size_t> simpleAnalyze(
    std::string const & inputText, uint8_t const & ngrams)
{
    // 1. Case fold to lower case
    std::string outText = asLower(inputText);

    // 2. Remove non-alphabetic non-space characters
    removeNotAlpha(outText);

    // 3. Tokenize words
    std::vector<std::string> tokenVect = tokenizeByWord(outText);
    // Capture number of words
    std::size_t const numWords = tokenVect.size();

    // 4. Remove stop words
    WordFilter::removeWords(tokenVect);

    // 5. Reduce words to their base form with stemming
    {  // TODO: either abstract the stemmer in olestem our write func
        stemming::english_stem<> EnglishStemmer;
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        for (auto & token : tokenVect)
        {
            std::wstring wtoken = converter.from_bytes(token);
            EnglishStemmer(wtoken);
            token = converter.to_bytes(wtoken);
        }
    }

    // 6. Construct n-grams
    ngramifyInplace(tokenVect, ngrams);

    return std::pair(tokenVect, numWords);
}


std::pair<std::vector<std::string>, std::size_t> fullAnalyze(
    std::string const & inputText, uint8_t const & ngrams)
{
    // TODO: implement in full
    auto pair = simpleAnalyze(inputText);
    pair.first = ngramify(pair.first, 2);
    return pair;
}

}
