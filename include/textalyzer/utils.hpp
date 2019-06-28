#pragma once

#include <unordered_map>
#include <vector>

namespace textalyzer
{
/**
 * @brief Creates an `unordered_map` of token frequencies.
 *
 * @tparam T
 * @param tokenVector
 * @return std::unordered_map<T, uint>
 */
template <typename T>
std::unordered_map<T, std::size_t> asFrequencyMap(
    std::vector<T> const & tokenVector);

}  // namespace textalyzer
