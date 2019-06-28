#include <textalyzer/utils.hpp>

namespace textalyzer
{
template <typename T>
std::unordered_map<T, std::size_t> asFrequencyMap(
    std::vector<T> const & tokenVector)
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

}  // namespace textalyzer
