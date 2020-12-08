//#include <vector>
#include <array>
#include "gmock/gmock.h"
#include "SumFinder.h"

using namespace AdventOfCode2020;
using namespace testing;

// These two numbers should add up to 2020
TEST (FindSums, TwoNumbers) {

    auto sumFinderObj = SumFinder(2020);

    std::vector<int> input{2000,20}; 
    auto returned = sumFinderObj.find2(input);

    ASSERT_THAT(returned, ElementsAre(2020,20));
}