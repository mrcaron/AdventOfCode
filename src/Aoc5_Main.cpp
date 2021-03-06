//#define _GLIBCXX_USE_CXX11_ABI 0

#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BoardingPass.h"

using namespace AdventOfCode2020;

// Note:
// Our problem says to solve for down 1 and right 3, which could be an input given to us, making this
// a generic map solver. I'll leave that for now because I simply want to get to the algorithm part.
int main(int argc, char** argv)
{
    // INPUT: --------------------------------------------------------------------------------------------------------------
    // INPUT: Check Input File Name
    std::string filename;
    if (argc < 2)
    {
        //std::cerr << "Please provide a filename for input." << std::endl;
        //return 1;
        filename = "../../puzzle_input.txt";
    } 
    else {
        filename = argv[1];
    }

    std::string sPath{filename};
    struct stat buffer;
    if (stat (sPath.c_str(), &buffer) != 0)
    {
        std::cerr << "!! ERROR !! : " << sPath << " doesn't exist. Please provide an existing input file." << std::endl;
        return 1; 
    }
    
    // END INPUT: ----------------------------------------------------------------------------------------------------------

    // PROCESS: ------------------------------------------------------------------------------------------------------------
    // slurp the input file into a vector
    auto fsInput = std::ifstream{ sPath };
    if (! fsInput)
    {
        std::cerr << "!! ERROR !! : opening " << sPath << " failed." << std::endl;
        return 1;
    }

    std::cout << "Not implemented yet!" << std::endl;

    return 0;
}