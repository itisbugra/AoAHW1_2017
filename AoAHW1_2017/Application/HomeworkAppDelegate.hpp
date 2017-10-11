#pragma once

#include "AppDelegate.hpp"

namespace Homework {
    class HomeworkAppDelegate : public AppDelegate {
    public:
        HomeworkAppDelegate(const Int32 argc, const Char *argv[]);
        
        ~HomeworkAppDelegate() noexcept override;
        
        void startApplication() const noexcept override;
    };
}
