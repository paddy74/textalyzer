#include <iostream>

#include <textalyzer/textalyzer.hpp>


int main(int argc, const char * argv[])
{
    std::string testStr = "Hello world, where are your documents? A strange query that is. I'm fine. You could say I feel like the number 1!  I guess we'll find out. Do you need to see some of my documentation?";

    auto const anlyzPair = textalyzer::lowAnalyze(testStr);

    std::cout << "Number of words: " << anlyzPair.second << std::endl;
    for (auto const & item : anlyzPair.first)
        std::cout << item << std::endl;

    return 0;
}
