#include "pch.h"
#include "CppUnitTest.h"
#include "..\\Markov.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MarkovTest
{
	TEST_CLASS(MarkovTest)
	{
	public:
		
		TEST_METHOD(TestLength)
		{
			String string_("kitten");
			int length = string_.length();
			Assert::AreEqual(length, 7);
		}
		TEST_METHOD(TestFindPositin)
		{
			String string_("cat");
			String str("at");
			Assert::AreEqual(string_.find_position(str), 1);
		}
		TEST_METHOD(TestReplace)
		{
			String string_("abbbcaa");
			String change_string("bb");
			String replaced_string("b");
			string_.replace(change_string, replaced_string);
			String result_string("abbcaa");
			Assert::AreEqual(string_ == result_string, true);
		}
		TEST_METHOD(TestOperators)
		{
			String string_("kit");
			String a("ten");
			String b = string_ + a;
			String c("kitten");
			Assert::AreEqual(true, b == c);
		}
		TEST_METHOD(TestPosition)
		{
			String string_("cat");
			char str = 't';
			Assert::AreEqual(str, string_[2]);
		}
		TEST_METHOD(TestSubstitution)
		{
			vector<Substitution> substitutions;
			String text("abbbcaa");
			Substitution rule1("aa", "a", false);
			substitutions.push_back(rule1);
			Substitution rule2("bb", "b", false);
			substitutions.push_back(rule2);
			Substitution rule3("cc", "c", true);
			substitutions.push_back(rule3);
			String result = Markov(text, substitutions);
			String res = "abca";
			Assert::IsTrue(result == res);
		}
	};
}
