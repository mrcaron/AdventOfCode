#include <string>
#include <sstream>
#include <cstddef>
#include <iostream>
#include "PassportVerifier.h"

// Some later TODO; I could use a BitSet to do this as well. 
bool AdventOfCode2020::PassportVerifier::Verify( std::string input )
{
    std::stringstream inputStream {input};
    std::byte passport {0};

    //std::cout << "  >> DEBUG << Input string: " << input << std::endl;

    for(std::string token; std::getline(inputStream, token, ' ');)
    {
        int pos = token.find(':');
        auto key = token.substr(0,pos);
        auto value = token.substr(pos+1);

        auto it = KEYS.find(key);
        if (it != KEYS.end())
        {
            //std::cout << "  >> DEBUG << KEY: " << it->first << std::endl;
            //std::cout << "  >> DEBUG << VALUE: " << static_cast<unsigned short>(it->second) << std::endl;
            passport |= it->second;
        }
    }
    
    //std::cout << "  >> DEBUG << PASSPORT VAL: " << static_cast<unsigned short>(passport) << std::endl;
    passport ^= std::byte{255};

    bool result =  static_cast<unsigned short>(passport) < 2;
    
    //std::cout << "  >> DEBUG << VALID?: " << (result ? "Y" : "N") << std::endl;
    return result;
}