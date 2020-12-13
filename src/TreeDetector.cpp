#include "TreeDetector.h"

#include <string>

bool AdventOfCode2020::TreeDetector::DetectTree(const int target, const char* scanLine)
{
    return scanLine[target % _iRightStep] == TREE;
}