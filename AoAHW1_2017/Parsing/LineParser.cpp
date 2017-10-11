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
    std::string copy(line);
    Size position = 0UL;
    std::string token;
    std::vector<std::string> result;
    
    while ((position = copy.find(delimiter)) != std::string::npos) {
        token = copy.substr(0, position);
        
        result.push_back(token);
        
        copy.erase(0, position + delimiter.length());
    }
    
    result.push_back(copy);
    
    return result;
}
