
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "BoardingPass.h"

using namespace AdventOfCode2020;
using namespace testing;


TEST(BoardingPass_SeatId, FBFBBFFRLR_357)
{
    std::string input = "BFFFBBFRRR";
    BoardingPass bp(input);
    ASSERT_EQ(44, bp.Row());
    ASSERT_EQ(5, bp.Column());
    ASSERT_EQ(357, bp.SeatId());
}

TEST(BoardingPass_SeatId, BFFFBBFRRR_567)
{
    std::string input = "BFFFBBFRRR";
    BoardingPass bp(input);
    ASSERT_EQ(70, bp.Row());
    ASSERT_EQ(7, bp.Column());
    ASSERT_EQ(567, bp.SeatId());
}

TEST(BoardingPass_SeatId, FFFBBBFRRR_119)
{
    std::string input = "FFFBBBFRRR";
    BoardingPass bp(input);
    ASSERT_EQ(14, bp.Row());
    ASSERT_EQ(7, bp.Column());
    ASSERT_EQ(567, bp.SeatId());
}

TEST(BoardingPass_SeatId, BBFFBBFRLL_820)
{
    std::string input = "BBFFBBFRLL";
    BoardingPass bp(input);
    ASSERT_EQ(102, bp.Row());
    ASSERT_EQ(4, bp.Column());
    ASSERT_EQ(567, bp.SeatId());
}
