#pragma once

#include "PrefixHeader.pch"

#include <vector>
#include <string>

namespace Homework {
    class FileParser {
    public:
        std::string fileName;

        FileParser(const std::string &fileName);

        auto parse() -> const std::vector<std::string>;
    };
}
