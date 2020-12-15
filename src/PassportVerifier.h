#pragma once

#include <string>
#include <set>

using namespace std::literals;

namespace AdventOfCode2020 {
    class PassportVerifier
    {
    private:
        inline static const std::set<std::string> _Keys {
            "byr"s,
            "iyr"s,
            "eyr"s,
            "hgt"s,
            "hcl"s,
            "ecl"s,
            "pid"s
        };
    public:
        PassportVerifier(/* Args */) {}
        ~PassportVerifier() {}

        bool Verify( std::string input );
    };
}