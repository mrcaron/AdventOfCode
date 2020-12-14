#include <sys/stat.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <memory>
#include "PasswordVerifier.h"
#include "TreeDetector.h"

using namespace AdventOfCode2020;

// Note:
// Our problem says to solve for down 1 and right 3, which could be an input given to us, making this
// a generic map solver. I'll leave that for now because I simply want to get to the algorithm part.
int main(int argc, char** argv)
{
    // INPUT: --------------------------------------------------------------------------------------------------------------
    // INPUT: Check Input File Name
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

    // INPUT: Check Input Right Step
    if (argc < 3)
    {
        std::cerr << "Please provide a right step." << std::endl;
        return 1;
    }
    int RightStep = atoi(argv[2]);
    if (RightStep == 0)
    {
        std::cerr << "Expected a right step > 0." << std::endl;
    }
    // END INPUT: ----------------------------------------------------------------------------------------------------------

    // PROCESS: ------------------------------------------------------------------------------------------------------------
    // slurp the input file into a vector
    auto fsInput = std::make_unique<std::ifstream>( std::ifstream{ sPath } );
    if (fsInput == nullptr)
    {
        std::cerr << "!! ERROR !! : opening " << sPath << " failed." << std::endl;
        return 1;
    }

    TreeDetector treeScanner(RightStep, std::move(fsInput) );
    
    std::cout << treeScanner.DetectTrees() << std::endl;

    return 0;
}