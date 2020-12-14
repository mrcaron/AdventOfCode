#include <memory>
#include <sstream>
#include <iostream>

#include "gmock/gmock.h"
#include "TreeDetector.h"

using namespace AdventOfCode2020;

TEST (TreeDetector_DetectTrees, NoTreesInSight)
{
    std::string input("...........");
    int size = input.length();

    for(int i=1; i<size; i++)
    {
        auto inputStream = std::istringstream{ input };
        TreeDetector td(0, i, inputStream);
        ASSERT_EQ(0, td.DetectTrees());
    }    
}

TEST (TreeDetector_DetectTrees, TreesEverywhere)
{
    std::string input("###########");
    int size = input.length();

    for(int i=1; i<size; i++)
    {
        auto inputStream = std::istringstream{ input };
        TreeDetector td(0, i, inputStream);
        ASSERT_EQ(1, td.DetectTrees());
    }    
}

TEST (TreeDetector_DetectTrees, NoTreesInSight_Continuum)
{
    std::string input("...........");

    for(int i=1; i<100; i++)
    {
        auto inputStream = std::istringstream{ input };
        TreeDetector td(0, i, inputStream);
        ASSERT_EQ(0, td.DetectTrees());
    }    
}

TEST (TreeDetector_DetectTrees, TreesEverywhere_Continuum)
{
    std::string input("###########");

    for(int i=1; i<100; i++)
    {
        auto inputStream = std::istringstream{ input };
        TreeDetector td(0, i, inputStream);
        ASSERT_EQ(1, td.DetectTrees());
    }    
}

void _ResetInput(std::stringstream &inputStream, const std::vector<std::string> &vInput)
{
    inputStream.clear();
    for (auto &&l : vInput)
    {
        inputStream << l << std::endl;
    }    
}

TEST (TreeDetector_DetectTree, SevenCorect_Slope1D3R)
{
    std::vector<std::string> inputData{
        "..##.......",
        "#...#...#..",
        ".#....#..#.",
        "..#.#...#.#",
        ".#...##..#.",
        "..#.##.....",
        ".#.#.#....#",
        ".#........#",
        "#.##...#...",
        "#...##....#",
        ".#..#...#.#"
    };


    std::stringstream sInputData;
    _ResetInput(sInputData, inputData);
    TreeDetector td(1, 3, sInputData);
    ASSERT_EQ(7, td.DetectTrees());
}

TEST (TreeDetector_DetectTree, SevenCorect_Slope2D1R)
{
    std::vector<std::string> inputData{
        "..##.......",
        "#...#...#..",
        ".#....#..#.",
        "..#.#...#.#",
        ".#...##..#.",
        "..#.##.....",
        ".#.#.#....#",
        ".#........#",
        "#.##...#...",
        "#...##....#",
        ".#..#...#.#"
    };

    std::stringstream sInputData;
    _ResetInput(sInputData, inputData);
    TreeDetector td(2, 1, sInputData);
    ASSERT_EQ(2, td.DetectTrees());
}

TEST (TreeDetector_DetectTree, SevenCorect_Slope3D2R)
{
    std::vector<std::string> inputData{
        "..##.......",
        "#...#...#..",
        ".#....#..#.",
        "..#.#...#.#",
        ".#...##..#.",
        "..#.##.....",
        ".#.#.#....#",
        ".#........#",
        "#.##...#...",
        "#...##....#",
        ".#..#...#.#"
    };

    std::stringstream sInputData;
    _ResetInput(sInputData, inputData);
    TreeDetector td(3, 2, sInputData);
    ASSERT_EQ(1, td.DetectTrees());
}

TEST (TreeDetector_DetectTree, SevenCorect_Slope2D3R)
{
    std::vector<std::string> inputData{
        "..##.......",
        "#...#...#..",
        ".#....#..#.",
        "..#.#...#.#",
        ".#...##..#.",
        "..#.##.....",
        ".#.#.#....#",
        ".#........#",
        "#.##...#...",
        "#...##....#",
        ".#..#...#.#"
    };

    std::stringstream sInputData;
    _ResetInput(sInputData, inputData);
    TreeDetector td(2, 3, sInputData);
    ASSERT_EQ(2, td.DetectTrees());
}