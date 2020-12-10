#include "PasswordVerifier.h"
#include <string>
#include <sstream>
#include <ctype.h>

AdventOfCode2020::PasswordVerifier::PasswordVerifier(std::string pattern)
{
    std::stringstream cBuff[2];
    int cCurrent = 0;

    // parse out the pattern
    for (auto &&i : pattern)
    {
        // ignore spaces
        if (i == '-')
        {
            cCurrent++;
        }
        else if (i == ' ') { continue; }
        else if (isalpha(i))
        {
            _cKey = i;
        }
        else // is digit
        {
            cBuff[cCurrent] << i;
        }
    }

    _iMin = std::stoi( cBuff[0].str() );
    _iMax = std::stoi( cBuff[1].str() );
}
    
AdventOfCode2020::PasswordVerifier::~PasswordVerifier()
{
}

int AdventOfCode2020::PasswordVerifier::GetMin() { return _iMin; }
int AdventOfCode2020::PasswordVerifier::GetMax() { return _iMax; }
char AdventOfCode2020::PasswordVerifier::GetKey() { return _cKey; }

bool AdventOfCode2020::PasswordVerifier::Validate(std::string password)
{
    // Pattern has a minimum and a maximum followed by a character
    // So you start at the minimum after you count it and end at the end of the 
    // string. There's no solution < O(N).

    int charCount = 0;
    for (auto &&i : password)
    {
        if ( i == _cKey) 
        { 
            charCount++;
        }
    }
       
    return charCount >= _iMin && charCount <= _iMax;
}