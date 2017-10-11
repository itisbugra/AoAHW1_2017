#include "PrefixHeader.pch"

#include "HomeworkAppDelegate.hpp"

Int32 main(const Int32 argc, const Char *argv[])
{
    using Homework::HomeworkAppDelegate;

    auto delegate = HomeworkAppDelegate(argc, argv);

    delegate.startApplication();

    return delegate.getExitStatus();
}
