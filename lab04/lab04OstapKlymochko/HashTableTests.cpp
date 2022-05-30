#include "pch.h"
#include <gtest/gtest.h>
#include"..//Hash Table/Table.cpp"
#include "..//Hash Table/HashTable.cpp"

HashTable t;

TEST(TableTest, AddTheItem)
{
    for (int i = 1; i <= 10; i++)
    {
        EXPECT_NO_THROW(t.addTheItemValue(("Key" + to_string(i)), i));
    }
}

TEST(TableTest, IsItemInArray)
{
    EXPECT_TRUE(t.isItemInTheTable("Key5"));
    EXPECT_FALSE(t.isItemInTheTable("Key100"));
    EXPECT_TRUE(t.isItemInTheTable("Key10"));
}

TEST(TableTest, ItemValue)
{
    EXPECT_EQ(t.getTheItem("Key10"), 10);
    EXPECT_EQ(t.getTheItem("Key4"), 4);
    EXPECT_EQ(t.getTheItem("Key1"), 1);
}

TEST(TableTest, HashFunction)
{
    t.clearTheHashMap();
    EXPECT_EQ(t.hash("a1"), 6);
    EXPECT_EQ(t.hash("b2"), 8);
}


TEST(TableTest, SizeOfTheHashMap)
{
    EXPECT_EQ(t.sizeOfTheHashMap(), 0);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
