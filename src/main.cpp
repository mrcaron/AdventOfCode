#include <sys/stat.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "SumFinder.h"

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

    std::vector<int> input{};
    char cBuffer[10]; // more than enough room to read a number < 2020
    while( fsInput )
    {
        fsInput.getline(cBuffer, 100);
        std::string strBuffer{ cBuffer };
        if (strBuffer.size() == 0)
        {
            std::cout << " DEBUG: picked up empty line " << std::endl;
        } 
        else {
            // don't expect non-integer lines like comments, etc
            std::cout << " DEBUG: read line [" << strBuffer << "]" << std::endl;
            input.push_back( std::stoi( strBuffer ) );
        }
    }    

    // run through the finder
    SumFinder finder(2020);
    auto returned = finder.Find2(input);

    if (returned.size() == 2)
    {
        std::cout << "(" << returned.at(0) << ", " << returned.at(1) << ")" << std::endl;
        std::cout << "Result: " << returned.at(0) * returned.at(1) << std::endl;
    }
    else 
    {
        std::cout << "Couldn't find two numbers to add up to 2020";
    }

    return 0;
}