#include <textalyzer/Analyzer.hpp>

#include <textalyzer/stringOps.hpp>
#include <textalyzer/WordFilter.hpp>
#include <textalyzer/ngramify.hpp>

#include <olestem/stemming/english_stem.h>

#include <codecvt>


namespace textalyzer
{

/* Public class methods */
/**
 * @brief Analyze a string of input text by calling a chain of methods:
 *  1. Case fold to lower case
 *  2. Remove non-alphabetic non-space characters
 *  3. Tokenize words
 *  4. Remove stop words
 *  5. Reduce words to their base form with stemming
 *
 * @param inputText
 * @return std::pair<std::vector<std::string>, uint>
 */
std::pair<std::vector<std::string>, std::size_t> Analyzer::simpleAnalyze(
    std::string const & inputText)
{
    // 1. Case fold to lower case
    std::string outText = toLowerCopy(inputText);

    // 2. Remove non-alphabetic non-space characters
    rmNonAlphaSpace(outText);

    // 3. Tokenize words
    std::vector<std::string> tokenVect = strSplit(outText);
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

    return std::pair(tokenVect, numWords);
}


std::pair<std::vector<std::string>, std::size_t> Analyzer::fullAnalyze(
    std::string const & inputText,
    uint8_t const & ngrams
)
{
    // TODO: implement in full
    auto pair = simpleAnalyze(inputText);
    pair.first = ngramify(pair.first, 2);
    return pair;
}


template<typename T>
std::unordered_map<T, std::size_t> Analyzer::asFrequencyMap(
    std::vector<T> const & tokenVector)
{
    std::unordered_map<T, std::size_t> freqMap;
    for (auto const & token : tokenVector)
    {
        if (freqMap.count(token) == 0)
            freqMap[token] = 1;
        else
            freqMap.at(token)++;
    }

    return freqMap;
}

}
