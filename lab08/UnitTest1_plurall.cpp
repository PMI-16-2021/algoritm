#include "pch.h"
#include "CppUnitTest.h"
#include "../plurall/plurall.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1plurall
{
	TEST_CLASS(UnitTest1plurall)
	{
	public:
		
		TEST_METHOD(add)
		{
			Set s;
			s.add(2);
			Assert::IsTrue(s.in(2));
			Assert::AreEqual(s.len(), 1);
		}
		TEST_METHOD(remove)
		{
			Set s;
			s.add(2);
			s.remove(2);
			Assert::IsFalse(s.in(2));
			Assert::AreEqual(s.len(), 0);
		}
		TEST_METHOD(len)
		{
			Set s;
			s.add(2);
			s.add(6);
			s.add(4);
			s.add(5);
			Assert::AreEqual(s.len(), 4);
		}
		TEST_METHOD(unionn)
		{
			Set s;
			s.add(2);
			s.add(6);
			s.add(4);
			Set s1;
			s1.add(1);
			s1.add(2);
			Set r;
			r = s.unionn(s1);
			int res[4] = { 2,6,4,1 };
			for (int i = 0; i < 4; ++i) {
				Assert::AreEqual(r[i], res[i]);
			}
		}
		TEST_METHOD(intersection)
		{
			Set s;
			s.add(2);
			s.add(6);
			s.add(1);
			Set s1;
			s1.add(1);
			s1.add(2);
			Set r;
			r = s.intersection(s1);
			int res[2] = { 2,1 };
			for (int i = 0; i < 2; ++i) {
				Assert::AreEqual(r[i], res[i]);
			}
		}
		TEST_METHOD(difference)
		{
			Set s;
			s.add(2);
			s.add(6);
			s.add(4);
			Set s1;
			s1.add(1);
			s1.add(2);
			Set r;
			r = s.difference(s1);
			int res[2] = { 6,4 };
			for (int i = 0; i < 2; ++i) {
				Assert::AreEqual(r[i], res[i]);
			}
		}
		TEST_METHOD(symmetricDifference)
		{
			Set s;
			s.add(2);
			s.add(6);
			s.add(4);
			Set s1;
			s1.add(1);
			s1.add(2);
			Set r;
			r = s.symmetricDifference(s1);
			int res[3] = { 6,4,1 };
			for (int i = 0; i < 3; ++i) {
				Assert::AreEqual(r[i], res[i]);
			}
		}
	};
}
