#pragma once
//#define _GLIBCXX_USE_CXX11_ABI 0

#include <string>
#include <cstddef>
#include <map>

using namespace std::literals;

namespace AdventOfCode2020 {
    class PassportVerifier
    {
    private:
        inline static const std::map<std::string, std::byte> KEYS{
            {"cid", std::byte{0b0000'0001}},
            {"iyr", std::byte{0b0000'0010}},
            {"eyr", std::byte{0b0000'0100}},
            {"hgt", std::byte{0b0000'1000}},
            {"hcl", std::byte{0b0001'0000}},
            {"ecl", std::byte{0b0010'0000}},
            {"pid", std::byte{0b0100'0000}},
            {"byr", std::byte{0b1000'0000}},
        };

    public:
        PassportVerifier(/* Args */) {}
        ~PassportVerifier() {}

        bool Verify( std::string input );
    };
}