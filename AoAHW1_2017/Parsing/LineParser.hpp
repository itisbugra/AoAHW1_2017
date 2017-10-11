#pragma once

#include <string>
#include <vector>

namespace Homework {
    class LineParser {
    public:
        std::string line;
        
        LineParser(const std::string &line);
        
        auto parse() const noexcept -> std::vector<std::string>;
    };
}
