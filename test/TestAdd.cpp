#include "gtest/gtest.h"
#include "add.h"

TEST (AddTest, TwoAndTwo) {
    ASSERT_EQ (Add(2, 2), 4);
}