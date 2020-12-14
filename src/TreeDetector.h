#pragma once

#include <string>
#include <istream>
#include <memory>

namespace AdventOfCode2020 {
    class TreeDetector
    {
    private:
        static const char TREE = '#';
        int _iRightStep;
        std::unique_ptr<std::istream> _pInputStream;
        bool DetectTree(const int target, const std::string& scanLine);
    public:
        TreeDetector(const int RightStep, std::unique_ptr<std::istream> inputStream) : _iRightStep(RightStep), _pInputStream(std::move(inputStream)) { }
        ~TreeDetector() {}

        int DetectTrees();
    };
    
}