
# Features

The following individual features are made available by this library:

- Case fold
- *(TODO)* Compound word breaking
- *(TODO)* Expand word contractions
- Remove non-alphabetic characters
- Remove non-alphanumeric characters
- Split words at a delimiter
- Count the number of words
- Remove stop words
- Porter stemming
- Create a term frequency map
- Create n-grams
- *(TODO)* Find word-embeddings

## The `Analyzer` class

A general `Analyzer` class provides the `simpleAnalyze` and `fullAnalyze` functions to conduct a series of text preprocessing steps on a string of text.

### `Analyzer::simpleAnalyze`

```cpp
#include <textalyzer/Analyzer.hpp>

std::pair<std::vector<std::string>, std::size_t> simplePair =
    Analyzer::simpleAnalyze(inputText);
```

- Case fold to lower case
- Remove non-alphabetic characters
- Capture the number of words
- Remove stop words
- Porter stemming

### `Analyzer::fullAnalyze`

```cpp
#include <textalyzer/Analyzer.hpp>

std::pair<std::vector<std::string>, std::size_t> fullPair =
    Analyzer::fullAnalyze(inputText, 2);
```

Conducts `simpleAnalyze` with the addition of:

- Create n-grams
- *(TODO)* Find word-embeddings
