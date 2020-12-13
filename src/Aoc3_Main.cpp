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
    std::ifstream fsInput(sPath);
    if (!fsInput)
    {
        std::cerr << "!! ERROR !! : opening " << sPath << " failed." << std::endl;
        return 1;
    }

    TreeDetector treeScanner(RightStep);
    char cBuffer[100]; // more than enough room to read a number < 2020
    int total = 0;
    // TODO: Our down step is 1 by default, we'll adjust this later to make room for an arbitrary down step.
    // since our default is to go down 1, we simply skip the first line of input
    fsInput.getline(cBuffer, 100); // Eat it into oblivion
    while( fsInput )
    {
        fsInput.getline(cBuffer, 100);
        //std::string strBuffer{ cBuffer };
        if (cBuffer[0] == '\n' || cBuffer[1] == '\n')
        {
            //std::cout << " DEBUG: picked up empty line " << std::endl;
        } 
        else {
            if (treeScanner.DetectTree(cBuffer)) {
                total++;
            }
        }
    }

    std::cout << "Total: " << total << std::endl;
    return 0;
}