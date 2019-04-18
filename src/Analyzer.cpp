#include <textalyzer/Analyzer.hpp>

#include <textalyzer/stringOps.hpp>
#include <textalyzer/WordFilter.hpp>

#include <olestem/stemming/english_stem.h>

#include <codecvt>


namespace textalyzer
{

/* Public class methods */
/**
 * @brief Analyze a string of input text by calling a chain of methods:
 *  1. Case fold to lower case
 *  2. Expand concatenations
 *  3. Remove other non-alphabetic characters
 *  4. Tokenize words
 *  5. Remove stop words
 *  6. Reduce words to their base form with stemming
 *
 * @param inputText
 * @return std::pair<std::vector<std::string>, uint>
 */
std::pair<std::vector<std::string>, std::size_t> Analyzer::simpleAnalyze(
    std::string const & inputText)
{
    // 1. Case fold to lower case
    std::string outText = toLowerCopy(inputText);

    // TODO: 2. Expand concatenations

    // 3.
    rmNonAlphaSpace(outText);

    // 4. Tokenize words
    std::vector<std::string> tokenVect = strSplit(outText);
    // Capture number of words
    std::size_t const numWords = tokenVect.size();

    // 5. Remove stop words
    WordFilter::removeWords(tokenVect);

    // 6. Reduce words to their base form with stemming
    {
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


template<typename T>
std::unordered_map<T, std::size_t> Analyzer::toFrequencyMap(
    std::vector<T> tokenVector)
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
