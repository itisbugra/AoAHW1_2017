#include "HomeworkAppDelegate.hpp"

#include <fstream>

#include "InvalidArgumentException.hpp"
#include "FileParser.hpp"
#include "LineParser.hpp"
#include "CardMarshaller.hpp"
#include "MergeSortingStrategy.hpp"
#include "InsertionSortingStrategy.hpp"

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
        CardMarshaller marshaller;
        std::vector<Card> cards;
        
        for (auto &eachLine : lines) {
            LineParser lineParser(eachLine);
            
            auto params = lineParser.parse();
            auto card = marshaller.unmarshall(params);
            
            cards.push_back(card);
        }
        
        static SortingStrategy *strategy = nullptr;
        
        if (arguments[2] == "-m") {
            strategy = new MergeSortingStrategy();
        } else if (arguments[2] == "-i") {
            strategy = new InsertionSortingStrategy();
        } else {
            throw InvalidArgumentException("invalid sorting algorithm");
        }
        
        if (arguments[1] == "-full") {
            strategy->sort(cards, SortingStrategy::Key::Class);
            strategy->sort(cards, SortingStrategy::Key::Cost);
            strategy->sort(cards, SortingStrategy::Key::Name);
        } else if (arguments[1] == "-filter") {
            strategy->sort(cards, SortingStrategy::Key::Type);
        } else {
            throw InvalidArgumentException("invalid sorting sequence");
        }
        
        delete strategy;
        
        std::ofstream outputFile(arguments[4]);
        
        for (auto &eachCard : cards) {
            outputFile << eachCard << std::endl;
        }
    } else {
        throw InvalidArgumentException("application needs 5 arguments to run");
    }
}
