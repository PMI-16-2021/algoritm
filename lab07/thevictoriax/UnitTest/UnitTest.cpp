#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab07/markov.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(Rules1)
		{
			String S("abccbbaadbcdd");
			std::vector<std::pair<String, String>> rules = { { "aa","a" }, { "bb","b" }, { "cc","c" }, { "dd","d"} };
			S.markov(rules);
			String result("abcbadbcd");
			Assert::AreEqual(std::string(result.getLetters()), std::string(result.getLetters()));
		}
		TEST_METHOD(Rules2)
		{
			String S("101");
			std::vector<std::pair<String, String>> rules = { {"|0", "0||"}, { "1","0|" }, { "0","" } };
			S.markov(rules);
			String result("|||||");
			Assert::AreEqual(std::string(result.getLetters()), std::string(result.getLetters()));
		}
		TEST_METHOD(Rules3)
		{
			String S("|||*|");
			std::vector<std::pair<String, String>> rules = { {"*", "+"} };
			S.markov(rules);
			String result("|||+|");
			Assert::AreEqual(std::string(result.getLetters()), std::string(result.getLetters()));
		}
	}; 
}
