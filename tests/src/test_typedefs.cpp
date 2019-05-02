#include <functional>
#include <iostream>
#include <textalyzer/Analyzer.hpp>

int main()
{
    textalyzer::AnlyzerFunType<std::string> _ =
        textalyzer::Analyzer::lowAnalyze;

    return 0;
}
