#include <textalyzer/Analyzer.hpp>

#include <textalyzer/stringOps.hpp>
#include <textalyzer/StopwordFilter.hpp>


namespace textalyzer
{

/* Public class methods */
/**
 * @brief Analyze a string of input text by calling a chain of methods to
 *  - Case fold to lower case
 *  - Remove non-alphanumeric non-whitespace characters
 *  - Split at spaces
 *  - Remove stop words
 *  - Convert words to their base forms
 *
 * @param inputText
 * @return std::pair<std::vector<std::string>, uint>
 */
std::pair<std::vector<std::string>, uint> Analyzer::simpleAnalyze(
    std::string const & inputText)
{
    // Case fold
    std::string outText = toLowerCopy(inputText);
    // Remove non-alphanumeric non-whitespace characters
    rmNonAlNumSpaceInplace(outText);

    // Split at space delimiter
    std::vector<std::string> tokenVect = strSplit(outText);
    // Capture number of words
    uint const numWords = tokenVect.size();

    // Remove stop words
    StopwordFilter::removeWords(tokenVect);

    // TODO: Convert words to thier base form.

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
            freqMap[token] = 0;
        else
            freqMap.at(token)++;
    }

    return freqMap;
}

}
