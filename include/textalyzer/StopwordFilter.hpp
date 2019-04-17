#pragma once


#include <vector>
#include <unordered_set>
#include <algorithm>


namespace textalyzer
{

/**
 * @brief Handle stopword removal
 *
 */
class StopwordFilter
{
public:
    /* Public member methods */

    void static removeWords(
        std::vector<std::string> & strVect,
        std::unordered_set<std::string> const & stopwordSet);
    void static removeWords(
        std::vector<std::string> & strVect,
        std::string const & language);
    void static removeWords(std::vector<std::string> & strVect);


    /* Public getters */

    std::unordered_set<std::string> static const & getStopwords(
        std::string const & language);
    std::unordered_set<std::string> static getStopwordsCopy(
        std::string const & language);

private:
    StopwordFilter() {}


    /* Private class methods */

    bool static const isStopwordOrEmpty(
        std::string const & str,
        std::unordered_set<std::string> const & stopwordSet
    );

    template<typename T>
    std::vector<T> static getSymDiff(
        std::vector<T> const & a,
        std::unordered_set<T> const & b
    );


    /* Private member variables */

    std::string static const DEFAULT_LANGUAGE;

    std::unordered_set<std::string> static const englishStopwords;
};

}
