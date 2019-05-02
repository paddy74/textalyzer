#pragma once

#include <unordered_map>
#include <vector>

namespace textalyzer
{
/**
 * @brief Expand word contractions such as: 'you're' -> 'you are'.
 *
 */
class WordExpander
{
   public:
    /* Public member methods */

    void static expandWords(
        std::vector<std::string> & wordVect,
        std::unordered_map<std::string, std::string> const & contractions);
    void static expandWords(
        std::vector<std::string> & wordVect, std::string const & language);
    void static expandWords(std::vector<std::string> & wordVect);

    void static expandWord(
        std::string & word,
        std::unordered_map<std::string, std::string> const & contractions);
    void static expandWord(std::string & word, std::string const & language);
    void static expandWord(std::string & word);

    /* Public getters */

    std::unordered_map<std::string, std::string> static const & getContractions(
        std::string const & language);

   private:
    WordExpander() {}

    /* Private static member variables */

    std::string static const DEFAULT_LANGUAGE;

    std::unordered_map<
        std::string, std::string> static const englishContractions;
};

}  // namespace textalyzer
