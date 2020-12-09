#include "SumFinder.h"
#include <iostream>
#include <vector>
#include <set>

AdventOfCode2020::SumFinder::SumFinder(int total) : _iTotal(total) {}

AdventOfCode2020::SumFinder::~SumFinder() {}

// look for two numbers that sum to this one
std::vector<int> AdventOfCode2020::SumFinder::find2(std::vector<int> input)
{
    std::set<int> alt{};
    for (const auto &i : input)
    {
        if (alt.find(i) != alt.end())
        {
            return std::vector<int>{i, _iTotal-i};
        }

        alt.insert(_iTotal-i);
    }

    // should never get here
    return std::vector<int>{};
}
