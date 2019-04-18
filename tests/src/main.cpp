#include <iostream>

#include <textalyzer/Analyzer.hpp>


int main(int argc, const char * argv[])
{
    std::string testStr = "Hello world, how are you?  I am fine. You could say I feel like the number 1!  I guess we'll find out.";

    auto const anlyzPair = textalyzer::Analyzer::simpleAnalyze(testStr);

    std::cout << "Number of words: " << anlyzPair.second << std::endl;
    for (auto const & item : anlyzPair.first)
        std::cout << item << std::endl;

    return 0;
}