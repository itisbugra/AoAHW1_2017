#include "AppDelegate.hpp"

using Homework::AppDelegate;

AppDelegate::AppDelegate(const std::vector<std::string> arguments) noexcept
    : arguments(arguments), exitStatus(0)
{
    //  Empty implementation
}

AppDelegate::AppDelegate(const Int32 argc, const Char *argv[]) noexcept
{
    std::vector<std::string> parsedArguments;
    
    for (Int32 i = 0; i < argc; ++i) {
        parsedArguments.push_back(std::string(argv[i]));
    }
    
    arguments = parsedArguments;
}

auto
AppDelegate::getArguments() const noexcept
-> const std::vector<std::string> &
{
    return arguments;
}

auto
AppDelegate::getExitStatus() const noexcept
-> Int32
{
    return exitStatus;
}
