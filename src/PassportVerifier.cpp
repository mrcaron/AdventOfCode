#include <string>
#include <sstream>
#include <cstddef>
#include "PassportVerifier.h"

bool AdventOfCode2020::PassportVerifier::Verify( std::string input )
{
    std::stringstream inputStream {input};
    std::byte passport {0};

    for(std::string token; std::getline(inputStream, token, ' ');)
    {
        int pos = token.find(':');
        auto key = token.substr(0,pos);
        auto it = KEYS.find(key);
        if (it != KEYS.end())
        {
            passport |= it->second;
        }
    }

    passport ^= std::byte{255};

    return static_cast<unsigned char>(passport) < 2;
}