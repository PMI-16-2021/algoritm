//
// Created by Ostap Kilbasovych on 12.05.2022.
//
#include <functions.h>
#include <gtest/gtest.h>

TEST(PolishNotationSetTests, toStringTest) {
    std::string expression1 = "((12*5)-8)/7";
    std::string expression2 = "12-5+6-99";
    std::string expression3 = "7-(4/2+7-12/(35/5))";

    EXPECT_EQ("12_5_*_8_-_7_/", getReversePolishNotation(expression1));
    EXPECT_EQ("12_5_-_6_+_99_-", getReversePolishNotation(expression2));
    EXPECT_EQ("7_4_2_/_7_+_12_35_5_/_/_-_-", getReversePolishNotation(expression3));
}

TEST(PolishNotationSetTests, calculatingTest) {
    std::string expression1 = "((12*5)-8)/2";
    std::string expression2 = "12-5+6-99";
    std::string expression3 = "7-(4/2+7-12/(35/5))";

    EXPECT_EQ(26, calculate(getReversePolishNotation(expression1)));
    EXPECT_EQ(-86.0, calculate(getReversePolishNotation(expression2)));
    EXPECT_EQ(-0.285714, calculate(getReversePolishNotation(expression3)));
}

TEST(PolishNotationSetTests, isOperatorTest) {
    char operatorsArray[5] = {'+', '-', '*', '/', '^'};
    for (int i = 0; i < 5; i++) {
        EXPECT_TRUE(isOperator(operatorsArray[i]));
    }
}

TEST(PolishNotationSetTests, isDigitTest) {
    char digitsArray[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 5; i++) {
        EXPECT_TRUE(isDigit(digitsArray[i]));
    }
}

TEST(PolishNotationSetTests, addTest) {
    std::string readyExpression = "1 89 +";
    std::string infixExpression = "1+89";
    double result = calculate(readyExpression);
    EXPECT_EQ(90.0, result);
    EXPECT_EQ(90.0, calculate(getReversePolishNotation(infixExpression)));
}

TEST(PolishNotationSetTests, substractTest) {
    std::string readyExpression = "1 89 -";
    std::string infixExpression = "1-89";
    double result = calculate(readyExpression);
    EXPECT_EQ(-88.0, result);
    EXPECT_EQ(-88.0, calculate(getReversePolishNotation(infixExpression)));
}

TEST(PolishNotationSetTests, multiplicationTest) {
    std::string readyExpression = "4 89 *";
    std::string infixExpression = "4*89";
    double result = calculate(readyExpression);
    EXPECT_EQ(356.0, result);
    EXPECT_EQ(356.0, calculate(getReversePolishNotation(infixExpression)));
}

TEST(PolishNotationSetTests, divisionTest) {
    std::string readyExpression = "4 5 /";
    std::string infixExpression = "4/5";
    double result = calculate(readyExpression);
    EXPECT_EQ(0.8, result);
    EXPECT_EQ(0.8, calculate(getReversePolishNotation(infixExpression)));
}

TEST(PolishNotationSetTests, powTest) {
    std::string readyExpression = "4 5 ^";
    std::string infixExpression = "4^5";
    double result = calculate(readyExpression);
    EXPECT_EQ(1024.0, result);
    EXPECT_EQ(1024.0, calculate(getReversePolishNotation(infixExpression)));
}