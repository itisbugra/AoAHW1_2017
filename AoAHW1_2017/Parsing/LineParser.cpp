#include "LineParser.hpp"

#include <sstream>
#include <iterator>

using Homework::LineParser;

LineParser::LineParser(const std::string &string)
: line(string)
{
    //  Empty implementation
}

auto
LineParser::parse() const noexcept
-> std::vector<std::string>
{
    std::istringstream stringStream(line);
    std::string buffer;
    std::vector<std::string> result;
    
    while (stringStream >> buffer) {
        result.push_back(buffer);
    }
    
    return result;
}
