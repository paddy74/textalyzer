#pragma once

#include <vector>
#include <unordered_set>


namespace textalyzer
{

class WordExpander
{
public:
    /* Public member methods */

    void static expandWords(
        std::vector<std::string> & wordVect, std::string const & language);
    void static expandWords(std::vector<std::string> & wordVect);


    /* Public getters */

    std::unordered_set<std::string> static const & getContractions(
        std::string const & language);

private:
    WordExpander() {}


    /* Private member variables */

    std::string static const DEFAULT_LANGUAGE;

    std::unordered_set<std::string> static const englishContractions;
};

}
