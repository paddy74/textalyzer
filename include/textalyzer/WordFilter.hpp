#pragma once

#include <unordered_set>
#include <vector>

namespace textalyzer
{
/**
 * @brief Handle stopword removal
 *
 */
class WordFilter
{
public:
    /* Public member methods */

    void static removeWords(
        std::vector<std::string> & wordVect,
        std::unordered_set<std::string> const & stopwordSet);
    void static removeWords(
        std::vector<std::string> & wordVect, std::string const & language);
    void static removeWords(std::vector<std::string> & wordVect);

    /* Public getters */

    std::unordered_set<std::string> static const & getStopwords(
        std::string const & language);
    std::unordered_set<std::string> static getStopwordsCopy(
        std::string const & language);

private:
    WordFilter() {}

    /* Private class methods */

    bool static isStopwordOrEmpty(
        std::string const & str,
        std::unordered_set<std::string> const & stopwordSet);

    template <typename T>
    std::vector<T> static getSymDiff(
        std::vector<T> const & a, std::unordered_set<T> const & b);

    /* Private member variables */

    std::string static const DEFAULT_LANGUAGE;

    std::unordered_set<std::string> static const englishStopwords;
};

}  // namespace textalyzer
