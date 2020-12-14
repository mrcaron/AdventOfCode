#include <memory>
#include <sstream>
#include <istream>

#include "gmock/gmock.h"
#include "TreeDetector.h"

using namespace AdventOfCode2020;

TEST (TreeDetector_DetectTrees, NoTreesInSight)
{
    std::string input("...........");

    for(int i=1; i<11; i++)
    {
        auto inputStream = std::make_unique<std::istringstream>( std::istringstream{ input } );
        TreeDetector td(i, std::move(inputStream));
        ASSERT_EQ(0, td.DetectTrees());
    }    
}

TEST (TreeDetector_DetectTrees, TreesEverywhere)
{
    std::string input("###########");
    int size = input.length();

    for(int i=1; i<size; i++)
    {
        auto inputStream = std::make_unique<std::istringstream>( std::istringstream{ input } );
        TreeDetector td(i, std::move(inputStream));
        ASSERT_EQ(size, td.DetectTrees());
    }    
}

// TEST (TreeDetector_DetectTree, SevenCorect)
// {
//     std::vector<std::string> inputData{
//         "..##.......", 
//         "#...#...#..",
//         ".#....#..#.",
//         "..#.#...#.#",
//         ".#...##..#.",
//         "..#.##.....",
//         ".#.#.#....#",
//         ".#........#",
//         "#.##...#...",
//         "#...##....#",
//         ".#..#...#.#"
//     };

//     TreeDetector td(3);

//     ASSERT_FALSE(td.DetectTree(3, inputData.at(1).c_str()));
//     ASSERT_TRUE(td.DetectTree(6, inputData.at(2).c_str()));
// }