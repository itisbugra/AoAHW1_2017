#include "FileParser.hpp"
#include "FileNotOpenedException.hpp"

#include <fstream>
#include <sstream>

using Homework::FileParser;

FileParser::FileParser(const std::string &fileName)
    : fileName(fileName)
{
    //  Empty implementation
}

auto
FileParser::parse()
-> const std::vector<std::string>
{
    std::ifstream inputFile(fileName);
    
    if (inputFile.is_open()) {
        std::string line;
        std::vector<std::string> result;
        
        while (std::getline(inputFile, line)) {
            std::istringstream stringStream(line);
            
            result.push_back(stringStream.str());
        }
        
        return result;
    } else {
        throw FileNotOpenedException("file could not be opened");
    }
}

