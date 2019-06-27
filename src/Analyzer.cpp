#include <pstem/stemming/english_stem.h>

#include <codecvt>
#include <textalyzer/Analyzer.hpp>
#include <textalyzer/WordFilter.hpp>
#include <textalyzer/caseFold.hpp>
#include <textalyzer/editCharacter.hpp>
#include <textalyzer/ngramify.hpp>
#include <textalyzer/tokenize.hpp>

namespace textalyzer
{
/* Public static member variables */

uint8_t const Analyzer::DEFAULT_NGRAMS = 2;
uint8_t const Analyzer::DEFAULT_DEMBEDDINGS = 10;

/* Low level analyzer */

AnlyzerRetType<std::string> Analyzer::lowAnalyze(
    std::string const & inputText, uint8_t const & ngrams)
{
    // 1. Case fold to lower case
    std::string outText = asLower(inputText);

    // 2. Remove non-alphabetic non-space characters
    removeNotAlpha(outText);

    // 3. Tokenize words
    std::vector<std::string> tokenVect = tokenizeByWord(outText);
    // Capture number of words
    std::size_t const numWords = tokenVect.size();

    // 4. Construct n-grams
    ngramifyInplace(tokenVect, ngrams);

    return std::pair(tokenVect, numWords);
}

/* Medium level analyzer */

AnlyzerRetType<std::string> Analyzer::medAnalyze(
    std::string const & inputText, uint8_t const & ngrams)
{
    // 1. Case fold to lower case
    std::string outText = asLower(inputText);

    // 2. Remove non-alphabetic non-space characters
    removeNotAlpha(outText);

    // 3. Tokenize words
    std::vector<std::string> tokenVect = tokenizeByWord(outText);
    // Capture number of words
    std::size_t const numWords = tokenVect.size();

    // 4. Remove stop words
    WordFilter::removeWords(tokenVect);

    // 5. Reduce words to their base form with stemming
    {  // TODO: either abstract the stemmer in olestem our write func
        stemming::english_stem<> EnglishStemmer;
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        for (auto & token : tokenVect)
        {
            std::wstring wtoken = converter.from_bytes(token);
            EnglishStemmer(wtoken);
            token = converter.to_bytes(wtoken);
        }
    }

    // 6. Construct n-grams
    ngramifyInplace(tokenVect, ngrams);

    return std::pair(tokenVect, numWords);
}

/* High level analyzer */

AnlyzerRetType<std::vector<std::string>> Analyzer::highAnalyze(
    std::string const & inputText, uint8_t const & dembeddings)
{
    // 1. Case fold to lower case
    std::string outText = asLower(inputText);

    // 2. Remove non-alphabetic non-space characters
    removeNotAlpha(outText);

    // 3. Tokenize words
    std::vector<std::string> tokenVect = tokenizeByWord(outText);
    // Capture number of words
    std::size_t const numWords = tokenVect.size();

    // 4. Remove stop words
    WordFilter::removeWords(tokenVect);

    // 5. TODO: Construct n-grams
    // tokenVect = ngramify(outText, ngrams);

    // 6. Construct word embeddings // TODO: this is temporary solution
    AnlyzerRetType<std::vector<std::string>> outPair;
    outPair.second = numWords;
    for (auto const & token : tokenVect)
    {
        std::vector<std::string> wordRow;
        for (uint d = 0; d < dembeddings; ++d) wordRow.push_back(token);
        outPair.first.push_back(std::vector<std::string>{token});
    }

    return outPair;
}

}  // namespace textalyzer
