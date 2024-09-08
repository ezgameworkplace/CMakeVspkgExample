// fmtCMake.cpp : Defines the entry point for the application.
//

#include "fmtCMake.h"
#include <fmt/core.h>
#include <iostream>

int main()
{
    for (int i = 10; i >= 0; --i) {
        fmt::print("{}\n", i);
    }
    fmt::print("\nPrintFinished!\n");
    std::cin.get();
    return 0;
}
