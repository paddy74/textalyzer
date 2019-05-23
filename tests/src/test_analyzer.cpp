#include <textalyzer/Analyzer.hpp>

#include "testData.hpp"

int main()
{
    std::string testStr = getTestData();
    auto anlyzPair = textalyzer::Analyzer::lowAnalyze(testStr, 2);

    testStr = getTestData();
    anlyzPair = textalyzer::Analyzer::medAnalyze(testStr, 2);

    testStr = getTestData();
    auto const highAnlyzPair = textalyzer::Analyzer::highAnalyze(testStr, 2);

    return 0;
}
