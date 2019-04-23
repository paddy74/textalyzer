#pragma once

#include <vector>
#include <unordered_map>


namespace textalyzer
{

/**
 * @brief Creates an `unordered_map` of token frequencies.
 *
 * @tparam T
 * @param tokenVector
 * @return std::unordered_map<T, uint>
 */
template<typename T>
std::unordered_map<T, std::size_t> toFrequencyMap(
    std::vector<T> const & tokenVector
)
{
    std::unordered_map<T, std::size_t> freqMap;
    for (auto const & token : tokenVector)
    {
        if (freqMap.count(token) == 0)
            freqMap[token] = 1;
        else
            freqMap.at(token)++;
    }

    return freqMap;
}

}