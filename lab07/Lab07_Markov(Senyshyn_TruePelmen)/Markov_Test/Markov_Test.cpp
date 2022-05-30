#include "pch.h"
#include "CppUnitTest.h"
#include"../Lab07_Markov/Markov.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MarkovTest
{
	TEST_CLASS(MarkovTest)
	{
	public:
		
		TEST_METHOD(Test_Length)
		{
			String string_("kitten");
			int length = string_.Length();
			Assert::AreEqual(length, 7);
		}
		
		TEST_METHOD(Test_Replace)
		{
			String string_("abbbcaa");
			String change_string("bb");
			String replaced_string("b");
			string_.replace(change_string, replaced_string);
			String result_string("abbcaa");
			Assert::AreEqual(string_ == result_string, true);
		}
		TEST_METHOD(Test_Find)
		{
			String string_("cat");
			String str("at");
			Assert::AreEqual(string_.Find(str), 1);
		}
		TEST_METHOD(Test_Operator)
		{
			String string_("kit");
			String a("ten");
			String b = string_ + a;
			String c("kitten");
			Assert::AreEqual(true, b == c);
		}
		
		TEST_METHOD(Test_Replacement)
		{
			vector<Replacement> substitutions;
			String text("abbbcaa");
			Replacement rule1("aa", "a", false);
			substitutions.push_back(rule1);
			Replacement rule2("bb", "b", false);
			substitutions.push_back(rule2);
			Replacement rule3("cc", "c", true);
			substitutions.push_back(rule3);
			String result = Markov(text, substitutions);
			String res = "abca";
			Assert::IsTrue(result == res);
		}
		TEST_METHOD(Test_Position)
		{
			String string_("cat");
			char str = 't';
			Assert::AreEqual(str, string_[2]);
		}
	};
}
