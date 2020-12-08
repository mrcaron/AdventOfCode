#include "SumFinder.h"
#include <iostream>

AdventOfCode2020::SumFinder::SumFinder(int total) : _iTotal(total) {}

AdventOfCode2020::SumFinder::~SumFinder() {}

// look for two numbers that sum to this one
std::vector<int> AdventOfCode2020::SumFinder::find2(std::vector<int> input)
{
    //naieve approach
    for (const auto &i : input)
    {
        std::cout << i << std::endl;
    }

    // unimplemented yet
    return std::vector<int>{};
}
