#include <iostream>
#include <textalyzer/Analyzer.hpp>

#include "testData.hpp"

int main()
{
    std::string testStr = getTestData();

    auto const anlyzPair = textalyzer::Analyzer::highAnalyze(testStr, 2);

    std::cout << "Test: highAnalyze\n----------------\n";
    std::cout << "Number of words: " << anlyzPair.second << std::endl << "[\n";
    for (auto const & wordRow : anlyzPair.first)
    {
        std::cout << "[";
        for (auto const & embed : wordRow) std::cout << embed << ", ";
        std::cout << "]" << std::endl;
    }

    return 0;
}
