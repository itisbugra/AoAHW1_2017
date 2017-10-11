#include "HomeworkAppDelegate.hpp"

#include "InvalidArgumentException.hpp"
#include "FileParser.hpp"

using Homework::HomeworkAppDelegate;

HomeworkAppDelegate::HomeworkAppDelegate(const Int32 argc, const Char *argv[])
: Homework::AppDelegate(argc, argv)
{
    //  Empty implementation
}

HomeworkAppDelegate::~HomeworkAppDelegate() noexcept
{
    //  Empty implementation
}

void
HomeworkAppDelegate::startApplication() const noexcept
{
    using Homework::FileParser;
    
    if (arguments.size() == 5) {
        //  Fetch the arguments from argument list
        auto inputFileName = arguments[3];
        auto outputFileName = arguments[4];
        
        //  Parse the input file
        FileParser parser(inputFileName.c_str());
        
        auto lines = parser.parse();
        
        
    } else {
        throw InvalidArgumentException("application needs 5 arguments to run");
    }
}
