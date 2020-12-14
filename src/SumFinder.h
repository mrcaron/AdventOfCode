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

        bool Find2(std::vector<int> input, int (&found_nums)[2]);
    };    
} // namespace AdventOfCode2020
