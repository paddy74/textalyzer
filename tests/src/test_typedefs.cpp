#include <textalyzer/Analyzer.hpp>

#include <iostream>

#include <functional>

int main(int argc, const char * argv[])
{
    textalyzer::AnlyzerFunType<std::string> _ =
        textalyzer::Analyzer::lowAnalyze;

    return 0;
}
