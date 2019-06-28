#include <algorithm>
#include <textalyzer/caseFold.hpp>

namespace textalyzer
{
void toLower(std::string & str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

std::string asLower(std::string const & str)
{
    std::string outStr = str;
    toLower(outStr);
    return outStr;
}

void toUpper(std::string & str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

std::string asUpper(std::string const & str)
{
    std::string outStr = str;
    toUpper(outStr);
    return outStr;
}

}  // namespace textalyzer
