#pragma once

#include <string>

namespace AdventOfCode2020
{
    class PasswordVerifier
    {
    private:
        char _cKey;
        int _iMin;
        int _iMax;
        
    public:
        PasswordVerifier(std::string pattern);
        ~PasswordVerifier();

        int GetMin();
        int GetMax();
        char GetKey();

        bool Validate(std::string password);
    };    
} // namespace AdventOfCode2020
