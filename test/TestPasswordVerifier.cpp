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