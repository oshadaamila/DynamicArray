#include "gtest/gtest.h"
#include "dynamicarray.h"
#include <exception>

TEST(DynamicArrayTest, createArray) {
    //Test whether we can create array
    DynamicArray<int> *d_array = new DynamicArray<int>();
}

TEST(DynamicArrayTest, addInteger) {
    //Test whether we can create array
    DynamicArray<int> d_array;
    //add integer
    d_array.append(1);
}

TEST(DynamicArrayTest, addString) {
    DynamicArray<string> d_array;
    d_array.append("test");
}

TEST(DynamicArrayTest, add100000Integers) {
    DynamicArray<int> d_array;
    for (int i =0;i<100000;i++){
        d_array.append(i);
    }
    
}

TEST(DynamicArrayTest, testGetSize) {
    DynamicArray<int> d_array;
    for (int i =0;i<1000;i++){
        d_array.append(i);
    }
    ASSERT_EQ(d_array.getSize(),1000);
    
}

TEST(DynamicArrayTest, testGet) {
    DynamicArray<int> d_array;
    for (int i =0;i<1000;i++){
        d_array.append(i);
    }
    ASSERT_EQ(d_array.get(0),0);
    ASSERT_EQ(d_array.get(225),225);
    ASSERT_EQ(d_array.get(950),950);
    try{
        d_array.get(-5);
    }catch(const char * s){
        ASSERT_EQ("Index out of range",s);
    }
    
    try{
        d_array.get(1500);
    }catch(const char * s){
        ASSERT_EQ("Index out of range",s);
    }
    
}

TEST(DynamicArrayTest, testFindInteger) {
    DynamicArray<int> d_array;
    for (int i =0;i<1000;i++){
        d_array.append(i);
    }
    ASSERT_EQ(d_array.find(22),22);
    ASSERT_EQ(d_array.find(1500),-1);
    ASSERT_EQ(d_array.find(-5),-1);
}

TEST(DynamicArrayTest, testFindString) {
    DynamicArray<string> d_array;
    d_array.append("zero");
    d_array.append("one");
    d_array.append("two");
    ASSERT_EQ(d_array.find("one"),1);
    ASSERT_EQ(d_array.find("1500"),-1);
}

TEST(DynamicArrayTest, testoperator) {
    DynamicArray<string> d_array;
    d_array.append("zero");
    d_array.append("one");
    d_array.append("two");
    ASSERT_EQ(d_array[0],"zero");
    ASSERT_EQ(d_array[2],"two");
}



