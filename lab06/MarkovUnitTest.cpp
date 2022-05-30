#include "pch.h"
#include "CppUnitTest.h"
#include "..//Project7/myString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MarkovUnitTest
{
	TEST_CLASS(MarkovUnitTest)
	{
	public:
		
		TEST_METHOD(GetLengthTest)
		{
			String s1 = "";
			Assert::AreEqual(s1.getSize(), 0);
			String s2 = "kitty";
			Assert::AreEqual(s2.getSize(), 5);
			String s3 = "a b";
			Assert::AreEqual(s3.getSize(), 3);
		}

		TEST_METHOD(FindTest)
		{
			String s = "hello kitty";
			Assert::AreEqual(s.find("kitty"), 6);
			Assert::AreEqual(s.find("hello"), 0);
			Assert::AreEqual(s.find("cat"), -1);
		}

		TEST_METHOD(ReplaceTest)
		{
			String s = "hello kitty";
			s.replace("kitty", "Oleg");
			String result = "hello Oleg";
			for (int i = 0; i < s.getSize(); ++i) {
				Assert::AreEqual(s[i], result[i]);
			}
		}

		TEST_METHOD(OperatorTest)
		{
			String s1 = "hello";
			String s2 = "kitty";
			String s3 = "kitty";
			Assert::IsFalse(s1 == s2);
			Assert::IsTrue(s2 == s3);

			String result = "hellokitty";
			String add = s1 + s2;
			for (int i = 0; i < add.getSize(); ++i) {
				Assert::AreEqual(add[i], result[i]);
			}
			
		}

		TEST_METHOD(MarkovTest)
		{
			std::vector<Rule> r;
			Rule r1("1", "k");
			r.push_back(r1);
			Rule r2("2", "i");
			r.push_back(r2);
			Rule r3("a", "t");
			r.push_back(r3);
			Rule r4("", "", true);
			r.push_back(r4);
			Rule r5("*", "y");
			r.push_back(r5);

			String result = "kitty";
			String m = markov(r, "12aa*");

			for (int i = 0; i < m.getSize(); ++i) {
				Assert::AreEqual(m[i], result[i]);
			}
		}
	};
}
