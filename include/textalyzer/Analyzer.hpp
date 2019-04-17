#pragma once

#include <vector>
#include <unordered_map>


namespace textalyzer
{

class Analyzer
{
public:
    /* Public class methods */

    // Simple analyze
    std::pair<std::vector<std::string>, uint> static simpleAnalyze(
        std::string const & inputText);


    // Full analyze
    std::pair<std::vector<std::string>, uint> static fullAnalyze(
        std::string const & inputText,
        uint8_t const & ngrams
    );

    std::pair<std::vector<std::string>, uint> static fullAnalyze(
        std::string const & inputText
    ) { return fullAnalyze(inputText, Analyzer::DEFAULT_GRAMS); }


    /**
     * @brief Creates an `unordered_map` of token frequencies.
     *
     * @param tokenVector
     * @return std::unordered_map<std::string, uint>
     */
    std::unordered_map<std::string, uint> static tokenVectToMap(
        std::vector<std::string> tokenVector
    );

private:
    Analyzer() {}


    /* Private member variables */

    uint8_t static const DEFAULT_GRAMS = 2;
};

}
