#include "pch.h"
#include "CppUnitTest.h"
#include "..//лр8/mnozhyna.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(MnozhynaTest) {
    public:
		TEST_METHOD(addTest) {
			MySet S;
			S.add('3');
			S.add('4');
			Assert::AreEqual(S.len(), 2);
		}
		TEST_METHOD(removeTest) {
			MySet S;
			S.add('1');
			S.add('6');
			S.remove('1');
			Assert::AreEqual(1, S.len());
		}
		TEST_METHOD(lenTest) {
			MySet S;
			S.add('5');
			S.add('0');
			Assert::AreEqual(2, S.len());
		}
		TEST_METHOD(inTest) {
			MySet S;
			S.add('7');
			Assert::IsTrue(S.in('7'));
			Assert::IsFalse(S.in('3'));
		}
		TEST_METHOD(UnionTest) {
			MySet S1;
			S1.add('3');
			S1.add('8');
			MySet S2;
			S2.add('3');
			S2.add('4');
			MySet S;
			S = S1.Union(S2);
			char result[3] = { '3', '8', '4' };
			for (size_t i = 0; i < 3; ++i) {
				Assert::AreEqual(S[i], result[i]);
			}
		}
		TEST_METHOD(intersectionTest) {
			MySet S1;
			S1.add('3');
			S1.add('5');
			MySet S2;
			S2.add('7');
			S2.add('3');
			MySet S;
			S = S1.intersection(S2);
			char result[1] = { '3'};
			for (size_t i = 0; i < 1; ++i) {
				Assert::AreEqual(S[i], result[i]);
			}
		}
		TEST_METHOD(differenceTest) {
			MySet S1;
			S1.add('8');
			S1.add('9');
			S1.add('2');
			MySet S2;
			S2.add('8');
			S2.add('6');
			MySet S;
			S = S1.difference(S2);
			char result[2] = { '9', '2' };
			for (size_t i = 0; i < 2; ++i) {
				Assert::AreEqual(S[i], result[i]);
			}
		}
		TEST_METHOD(symmetric_differenceTest) {
			MySet S1;
			S1.add('8');
			S1.add('1');
			S1.add('3');
			MySet S2;
			S2.add('0');
			S2.add('1');
			MySet S;
			S = S1.symmetric_difference(S2);
			char result[3] = { '8', '3', '0'};
			for (size_t i = 0; i < 3; ++i) {
				Assert::AreEqual(S[i], result[i]);
			}
		}
	};
}