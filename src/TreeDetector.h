#pragma once

#include <string>
#include <istream>
#include <memory>

namespace AdventOfCode2020 {
    class TreeDetector
    {
    private:
        static const char TREE = '#';
        int _iDownStep, _iRightStep;
        std::istream& _sInput;
        bool detectTree(const int target, const std::string& scanLine);
    public:
        TreeDetector(const int DownStep, const int RightStep, std::istream& inputStream) : _iDownStep(DownStep), _iRightStep(RightStep), _sInput(inputStream) { }
        ~TreeDetector() {}

        int DetectTrees();
    };
    
}