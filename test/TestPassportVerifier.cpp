
// 

#include <string>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "PassportVerifier.h"

using namespace AdventOfCode2020;
using namespace testing;

TEST(PassportVerifier_Verify, All_Fields_OK)
{
    std::string input = "ecl:gry pid:860033327 eyr:2020 hcl:#fffffd byr:1937 iyr:2017 cid:147 hgt:183cm";

    PassportVerifier p;
    ASSERT_TRUE(p.Verify(input));
}

TEST(PassportVerifier_Verify, Missing_HGT_NOK)
{
    std::string input = "iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884 hcl:#cfa07d byr:1929";

    PassportVerifier p;
    ASSERT_FALSE(p.Verify(input));
}

TEST(PassportVerifier_Verify, Missing_CID_OK)
{
    std::string input = "hcl:#ae17e1 iyr:2013 eyr:2024 ecl:brn pid:760753108 byr:1931 hgt:179cm";

    PassportVerifier p;
    ASSERT_TRUE(p.Verify(input));
}

TEST(PassportVerifier_Verify, MISSING_CID_AND_BYR_NOK)
{
    std::string input = "hcl:#cfa07d eyr:2025 pid:166559648 iyr:2011 ecl:brn hgt:59in";

    PassportVerifier p;
    ASSERT_FALSE(p.Verify(input));
}
