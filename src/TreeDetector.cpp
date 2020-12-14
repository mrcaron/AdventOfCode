#include "TreeDetector.h"

#include <string>

bool AdventOfCode2020::TreeDetector::DetectTree(const int target, const std::string& scanLine)
{
    return scanLine[target % scanLine.length()] == TREE;
}

int AdventOfCode2020::TreeDetector::DetectTrees() { 

    // TODO: RE-IMPLEMENT HERE
    //
    // char cBuffer[100]; // more than enough room to read a number < 2020
    // int total = 0;
    // // TODO: Our down step is 1 by default, we'll adjust this later to make room for an arbitrary down step.
    // // since our default is to go down 1, we simply skip the first line of input
    // int currentLine = 1;
    // int currentPos = 0;
    // fsInput.getline(cBuffer, 100); // Eat it into oblivion
    // while( fsInput )
    // {
    //     fsInput.getline(cBuffer, 100);
    //     //std::string strBuffer{ cBuffer };
    //     if (cBuffer[0] == '\n' || cBuffer[1] == '\n')
    //     {
    //         //std::cout << " DEBUG: picked up empty line " << std::endl;
    //     } 
    //     else {
    //         total += treeScanner.DetectTree(currentLine*RightStep, cBuffer) ? 
    //             1 : 0;
    //     }
    // }

    // std::cout << "Total: " << total << std::endl;

    return 0; 
}