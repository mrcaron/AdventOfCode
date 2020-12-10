#include <sys/stat.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "PasswordVerifier.h"

using namespace AdventOfCode2020;

int main(int argc, char** argv)
{
    // read from expense report and find the TWO entries taht sum to 2020, 
    // then multiply those together
    if (argc < 2)
    {
        std::cerr << "Please provide a filename for input." << std::endl;
        return 1;
    }
    std::string sPath{argv[1]};
    struct stat buffer;
    if (stat (sPath.c_str(), &buffer) != 0)
    {
        std::cerr << "!! ERROR !! : " << sPath << " doesn't exist. Please provide an existing input file." << std::endl;
        return 1; 
    }

    // slurp the input file into a vector
    std::ifstream fsInput(sPath);
    if (!fsInput)
    {
        std::cerr << "!! ERROR !! : opening " << sPath << " failed." << std::endl;
        return 1;
    }

    char cBuffer[100]; // more than enough room to read a number < 2020

    int total = 0;
    while( fsInput )
    {
        fsInput.getline(cBuffer, 100);
        std::string strBuffer{ cBuffer };
        if (strBuffer.size() == 0)
        {
            //std::cout << " DEBUG: picked up empty line " << std::endl;
        } 
        else {
            // don't expect non-integer lines like comments, etc
            //std::cout << " DEBUG: read line [" << strBuffer << "]" << std::endl;
            int pattBreak = strBuffer.find(':');

            // doing it this way is probably not efficient as we may run into the same pattern more than once
            // better would be to put these verifier objects into a map and look them up, but just 
            // looking to get the algorithm correct suffices for me.
            PasswordVerifier verifer(strBuffer.substr(0,pattBreak));
                        
            bool result = verifer.Validate(strBuffer.substr(pattBreak+2));
            result ? total++ : 0;
            std::cout << strBuffer << " = " << result << std::endl;
        }
    }    

    std::cout << "Total: " << total << std::endl;
    return 0;
}