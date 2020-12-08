// Depends on a compiler that supports pragma once (i.e. VC, GCC 3.4)
#pragma once

#include <vector>

namespace AdventOfCode2020
{
    class SumFinder
    {
    private:
        int _iTotal;
    public:
        SumFinder(int total);
        ~SumFinder();

        std::vector<int> find2(std::vector<int> input);
    };    
} // namespace AdventOfCode2020
