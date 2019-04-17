#include <textalyzer/Analyzer.hpp>

#include <textalyzer/stringOps.hpp>
#include <textalyzer/StopwordFilter.hpp>


namespace textalyzer
{

/**
 * @brief Analyze a string of input text by calling a chain of methods to
 *  - Case fold to lower case
 *  - Remove non-alphanumeric non-whitespace characters
 *  - Split at spaces
 *  - Remove stop words
 *  - Convert words to their base forms
 *
 */
std::pair<std::vector<std::string>, uint> Analyzer::simpleAnalyze(
    std::string const & inputText)
{
    // Case fold
    std::string outText = toLowerCopy(inputText);
    // Remove non-alphanumeric non-whitespace characters
    rmNonAlNumSpaceInplace(outText);

    // Split at space delimiter
    std::vector<std::string> anlyzVect = strSplit(outText);
    // Capture number of words
    uint const numWords = anlyzVect.size();

    // Remove stop words
    StopwordFilter::removeWords(anlyzVect);

    // TODO: Convert words to thier base form.

    return std::pair(anlyzVect, numWords);
}

}
