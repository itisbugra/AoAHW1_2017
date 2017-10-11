#pragma once

#include "PrefixHeader.pch"

#include <vector>
#include <string>

namespace Homework {
    class AppDelegate {
    public:
        explicit AppDelegate(const std::vector<std::string> arguments) noexcept;
        explicit AppDelegate(const Int32 argc, const Char *argv[]) noexcept;

        virtual ~AppDelegate() noexcept = default;

        virtual void startApplication() const noexcept = 0;
        
        virtual auto getArguments() const noexcept -> const std::vector<std::string> &;
        virtual auto getExitStatus() const noexcept -> Int32;

    protected:
        std::vector<std::string> arguments;
        Int32 exitStatus = 0;
    };
}
