#pragma once

#include <string>

namespace AdventOfCode2020 {
    class TreeDetector
    {
    private:
        static const char TREE = '#';
        int _iRightStep;
    public:
        TreeDetector(const int RightStep) : _iRightStep(RightStep) {}
        ~TreeDetector() {}

        bool DetectTree(const int target, const char* scanLine);
    };
    
}