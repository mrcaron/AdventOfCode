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
            // TODO: Implement algorithm
        }
    }    

    std::cout << "Total: " << total << std::endl;
    return 0;
}