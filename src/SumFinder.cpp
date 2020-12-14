#include "SumFinder.h"
#include <iostream>
#include <vector>
#include <set>

AdventOfCode2020::SumFinder::SumFinder(int total) : _iTotal(total) {}

AdventOfCode2020::SumFinder::~SumFinder() {}

// look for two numbers that sum to this one
// expects an array of size 2
bool AdventOfCode2020::SumFinder::Find2(std::vector<int> input, int (&found_nums)[2])
{
    std::set<int> alt{};
    bool found = false;
    for(int i = 0; i < input.size() && !found; i++)
    for (const auto &i : input)
    {
        if (alt.find(i) != alt.end())
        {
            found_nums[0] = i;
            found_nums[1] = _iTotal-i;
            found = true;
        } else 
        {
            alt.insert(_iTotal-i);
        }
    }
    
    return found;
}
