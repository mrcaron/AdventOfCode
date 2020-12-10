#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "PasswordVerifier.h"

using namespace AdventOfCode2020;
using namespace testing;
using namespace std::literals;

//using ::std::vector;
//using ::testing::UnorderedElementsAre;
//using ::testing::A;

TEST (PasswordVerifier_Create, OneToThree_As)
{
    PasswordVerifier verifierObj("1-3 a"s );
    
    ASSERT_EQ('a', verifierObj.GetKey());
    ASSERT_EQ(1, verifierObj.GetMin());
    ASSERT_EQ(3, verifierObj.GetMax());
}
TEST (PasswordVerifier_Create, SixteenToTwenty_Js)
{
    PasswordVerifier verifierObj("16-20 j"s );
    
    ASSERT_EQ('j', verifierObj.GetKey());
    ASSERT_EQ(16, verifierObj.GetMin());
    ASSERT_EQ(20, verifierObj.GetMax());
}

TEST (PasswordVerifier_Verify, OneToThreeAs_ValidInput) {

    PasswordVerifier verifierObj("1-3 a"s );
    std::string input{ "abcde"s };
    auto returned = verifierObj.Validate(input);
    ASSERT_TRUE(returned);
}

TEST (PasswordVerifier_Verify, OneToThreeAs_InvalidInput) {
    PasswordVerifier verifierObj("1-3 a"s );
    std::string input{ "bbbbb"s };
    auto returned = verifierObj.Validate(input);
    ASSERT_FALSE(returned);
}