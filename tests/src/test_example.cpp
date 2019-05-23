#include <iostream>
#include <textalyzer/Analyzer.hpp>

#include "testData.hpp"

int main()
{
    std::string testStr = getTestData();

    auto const anlyzPair = textalyzer::Analyzer::medAnalyze(testStr, 2);

    std::cout << "Test: medAnalyze\n----------------\n";
    std::cout << "Number of words: " << anlyzPair.second << std::endl << "[";
    for (auto const & item : anlyzPair.first) std::cout << item << ", ";
    std::cout << "]" << std::endl;

    return 0;
}
