#pragma once

#include <string>

namespace AdventOfCode2020
{
    class PasswordVerifier
    {
    private:
        std::string _sPattern;
    public:
        PasswordVerifier(std::string pattern);
        ~PasswordVerifier();

        bool Validate(std::string password);
    };    
} // namespace AdventOfCode2020
