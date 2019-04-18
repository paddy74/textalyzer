#include <textalyzer/Analyzer.hpp>

#include <textalyzer/stringOps.hpp>
#include <textalyzer/WordFilter.hpp>


namespace textalyzer
{

/* Public class methods */
/**
 * @brief Analyze a string of input text by calling a chain of methods:
 *  1. Case fold to lower case
 *  2. Remove numbers
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

    // 2, 3.
    rmNonAlphaSpace(outText);

    // 4. Tokenize words
    std::vector<std::string> tokenVect = strSplit(outText);
    // Capture number of words
    std::size_t const numWords = tokenVect.size();

    // 5. Remove stop words
    WordFilter::removeWords(tokenVect);

    // TODO: 6. Reduce words to their base form with stemming

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
