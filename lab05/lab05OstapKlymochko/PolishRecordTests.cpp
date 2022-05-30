#include"pch.h"
#include <gtest/gtest.h>
#include "..//polish record/PolishRecord.cpp"

TEST(PolishTest, IsSign)
{
    EXPECT_FALSE(isSign('d'));
    EXPECT_TRUE(isSign('+'));
    EXPECT_TRUE(isSign('/'));
    EXPECT_FALSE(isSign('0'));
}

TEST(PolishTest, SignToInt)
{
    EXPECT_EQ(signToInt('*'), 2);
    EXPECT_EQ(signToInt('/'), 2);
    EXPECT_EQ(signToInt('d'), (-1));
    EXPECT_EQ(signToInt('-'), 1);
}


TEST(PolishTest, toPolish)
{
    EXPECT_EQ(toPolish("(4*(12+3)/2*(5+5)-(100*2))/2"), "4 12 3 + *2 /5 5 + *100 2 * - 2 /");
    EXPECT_EQ(toPolish("100+(23-10/2)"), "100 23 10 2 / - +");
    EXPECT_EQ(toPolish("20*5"), "20 5 *");
}


TEST(PolishTest, FunctionToEvaluate)
{
    string expr = toPolish("(4*(12+3)/2*(5+5)-(100*2))/2");
    EXPECT_EQ(functionToEvaluate(expr), 50);

    EXPECT_EQ(functionToEvaluate("28 4 /"), 7);
    EXPECT_EQ(functionToEvaluate("4 4 *"), 16);
    EXPECT_EQ(functionToEvaluate("4 10 +"), 14);

    EXPECT_NO_THROW(functionToEvaluate);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}