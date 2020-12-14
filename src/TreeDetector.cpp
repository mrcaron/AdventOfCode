#include "TreeDetector.h"

#include <string>

bool AdventOfCode2020::TreeDetector::detectTree(const int target, const std::string& scanLine)
{
    return scanLine[target % scanLine.length()] == TREE;
}

int AdventOfCode2020::TreeDetector::DetectTrees() 
{ 
    int total = 0;
    int loc = 0;
    int pos = 0;

    for(std::string sBuffer; std::getline(_sInput, sBuffer); loc++)
    {
        if ( _iDownStep > 0 && ( loc < _iDownStep || loc % _iDownStep )) 
        { 
            continue;
        }
        else
        //if (_iDownStep < 1 || ! loc % _iDownStep)
        {
            pos += _iRightStep;
            int numTree = (int)detectTree( pos, sBuffer);
            total += numTree;
        }
    }

    return total; 
}