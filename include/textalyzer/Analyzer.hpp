#pragma once

#include <string>
#include <vector>


namespace textalyzer
{

class Analyzer
{
public:
    /* Public class methods */

    // Simple analyze
    std::pair<std::vector<std::string>, std::size_t> static simpleAnalyze(
        std::string const & inputText);


    // Full analyze
    std::pair<std::vector<std::string>, std::size_t> static fullAnalyze(
        std::string const & inputText,
        uint8_t const & ngrams
    );

    std::pair<std::vector<std::string>, std::size_t> static fullAnalyze(
        std::string const & inputText
    ) { return fullAnalyze(inputText, Analyzer::DEFAULT_GRAMS); }

private:
    Analyzer() {}


    /* Private member variables */

    uint8_t static const DEFAULT_GRAMS = 2;
};

}
