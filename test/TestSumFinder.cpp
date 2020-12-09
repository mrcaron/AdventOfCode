#include <vector>
#include "gmock/gmock.h"
#include "SumFinder.h"

using namespace AdventOfCode2020;

using ::std::vector;
using ::testing::UnorderedElementsAre;
using ::testing::A;

// These two numbers should add up to 2020
TEST (FindSums, TwoNumbers) {

    auto sumFinderObj = SumFinder(2020);

    vector<int> input{2000,20}; 
    auto returned = sumFinderObj.find2(input);

    ASSERT_THAT(returned.at(0), A<int>());
    ASSERT_THAT(returned, A<vector<int>>());
    ASSERT_THAT(returned, UnorderedElementsAre(2000,20));
}