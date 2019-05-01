#include <textalyzer/Analyzer.hpp>

#include <iostream>

#include <functional>

int main()
{
    textalyzer::AnlyzerFunType<std::string> _ =
        textalyzer::Analyzer::lowAnalyze;

    return 0;
}
