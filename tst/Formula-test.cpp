#include "gtest/gtest.h"
#include "dynamicarray.h"

TEST(blaTest, test1) {
    //arrange
    //act
    //assert
    DynamicArray *d_array = new DynamicArray();
    EXPECT_EQ (d_array->getOne(),  1);
}
