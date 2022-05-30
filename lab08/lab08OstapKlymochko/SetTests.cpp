#include "pch.h"
#include <gtest/gtest.h>
#include "..//Set/Set.h"

Set<int> setter;

TEST(SetTest, Insert)
{
    setter.insert(10);
    setter.insert(10);
    EXPECT_EQ(setter.size(), 1);
    for (int i = 0; i < 10; i++)
    {
        setter.insert(i);
    }
    EXPECT_EQ(setter.size(), 11);
}

TEST(SetTest, Find)
{
    EXPECT_FALSE(setter.find(90));
    EXPECT_TRUE(setter.find(9));
    EXPECT_TRUE(setter.find(2));
}

TEST(SetTest, Erase)
{
    for (int i = 0; i < 10; i++)
    {
        EXPECT_NO_THROW(setter.erase(i));
    }

    EXPECT_EQ(setter.size(), 1);
}

TEST(SetTest, ClearEmpty)
{
    EXPECT_FALSE(setter.empty());
    setter.clear();
    EXPECT_TRUE(setter.empty());
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}