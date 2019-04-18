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
     * @tparam T
     * @param tokenVector
     * @return std::unordered_map<T, uint>
     */
    template<typename T>
    std::unordered_map<T, std::size_t> static toFrequencyMap(
        std::vector<T> tokenVector
    );

private:
    Analyzer() {}


    /* Private member variables */

    uint8_t static const DEFAULT_GRAMS = 2;
};

}
