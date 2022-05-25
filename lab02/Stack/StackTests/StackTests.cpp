#include "pch.h"
#include "CppUnitTest.h"
#include "..\\Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackTests
{
    TEST_CLASS(StackTests)
    {
    public:

        TEST_METHOD(TestingOperatorConstructors)
        {
            Stack S = Stack();
            Assert::AreEqual(S.isEmpty(), true);
            S.push(7);
            Stack S1(S);
            Assert::AreEqual(S1.isEmpty(), false);
            Stack S2 = S;
            Assert::AreEqual(S2.isEmpty(), false);
        }

        TEST_METHOD(TestingPopPush)
        {
            Stack S = Stack();
            S.push(1);
            S.push(3);
            S.push(4);
            S.pop();
            Assert::AreEqual(S.top(), 3.);
        }

        TEST_METHOD(TestingIsEmptyTopSize)
        {
            Stack S = Stack();
            Assert::AreEqual(S.isEmpty(), true);
            S.push(5);
            Assert::AreEqual(S.isEmpty(), false);
            S.push(6);
            S.push(7);
            S.push(3);
            Assert::AreEqual(S.top(), 3.);
            Assert::AreEqual(S.size(), 4);
        }

        TEST_METHOD(TestingSwapEmplace)
        {
            Stack S = Stack();
            S.push(4);
            S.push(8);
            S.push(3);
            S.push(5);
            S.pop();
            Stack S1 = Stack();
            S1.push(5);
            S1.push(3);
            S1.push(1);
            S.swap(S1);
            Assert::AreEqual(S.top(), 1.);
            S.emplace(6);
            Assert::AreEqual(S.top(), 6.);
        }
    };
}
