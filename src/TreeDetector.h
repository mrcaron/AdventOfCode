#pragma once

#include <string>

namespace AdventOfCode2020 {
    class TreeDetector
    {
    private:
        static const char TREE = '#';
        int _iRightStep;
    public:
        TreeDetector(int RightStep) : _iRightStep(RightStep) {}
        ~TreeDetector() {}

        bool DetectTree(const char* scanLine);
    };
    
}