#include <vector>
#include "gmock/gmock.h"
#include "SumFinder.h"

using namespace AdventOfCode2020;

using ::std::vector;
using ::testing::UnorderedElementsAreArray;
using ::testing::A;

TEST (SumFinder_Find2, TwoNumbers) {

    auto sumFinderObj = SumFinder(2020);

    vector<int> input{2000,20}; 
    int found[2];
    auto returned = sumFinderObj.Find2(input,found);

    ASSERT_TRUE(returned);
    ASSERT_THAT(found, UnorderedElementsAreArray({2000,20}));
}

TEST (SumFinder_Find2, TwoNumbers_NoSum) {

    auto sumFinderObj = SumFinder(2021);

    vector<int> input{2000,20}; 
    int found[2];
    auto returned = sumFinderObj.Find2(input,found);

    ASSERT_FALSE(returned);
}

TEST (SumFinder_Find5, FiveNumbers) {

    auto sumFinderObj = SumFinder(2020);

    vector<int> input{1721,979,366,299,675,1456};    
    int found[2];
    auto returned = sumFinderObj.Find2(input,found);

    ASSERT_TRUE(returned);
    ASSERT_THAT(found, UnorderedElementsAreArray({1721,299}));
}