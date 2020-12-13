#include "gmock/gmock.h"
#include "TreeDetector.h"

using namespace AdventOfCode2020;

TEST (TreeDetector_DetectTree, None_RightStep1Basic)
{
    TreeDetector td(1);

    for (int i=0;i<11;i++)
    {
        bool result = td.DetectTree(i, "...........");
        ASSERT_FALSE(result);
    }
}

TEST (TreeDetector_DetectTree, All_RightStep1Basic)
{
    TreeDetector td(1);

    for (int i=0;i<11;i++)
    {
        bool result = td.DetectTree(i, "###########");
        ASSERT_TRUE(result);
    }
}

TEST (TreeDetector_DetectTree, None_RightStep1Continuum)
{
    TreeDetector td(1);

    for (int i=0;i<100;i++)
    {
        bool result = td.DetectTree(i, "...........");
        ASSERT_FALSE(result);
    }
}

TEST (TreeDetector_DetectTree, All_RightStep1Continuum)
{
    TreeDetector td(1);

    for (int i=0;i<100;i++)
    {
        bool result = td.DetectTree(i, "###########");
        ASSERT_TRUE(result);
    }
}