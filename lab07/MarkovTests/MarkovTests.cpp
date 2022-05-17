#include "pch.h"
#include "CppUnitTest.h"
#include "../MarkovAlogorithm/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MarkovTests
{
	TEST_CLASS(MarkovTests)
	{
	public:
		
		TEST_METHOD(Test_Multiplication)
		{
			std::vector<Rule> rules;
			Rule a1("|b", "ba|");
			Rule a2("ab", "ba");
			Rule a3("b", "");
			Rule a4("*|", "b*");
			Rule a5("*", "c");
			Rule a6("|c", "c");
			Rule a7("ac", "c|");
			Rule a8("c", "", true);
			rules.push_back(a1);
			rules.push_back(a2);
			rules.push_back(a3);
			rules.push_back(a4);
			rules.push_back(a5);
			rules.push_back(a6);
			rules.push_back(a7);
			rules.push_back(a8);
			String result = markovAlg(rules, "||||*|||");
			String expected = "||||||||||||"; 
			int checker = 0;
			auto exp_iter = expected.begin();
			for (auto i = expected.begin(); i < expected.end() ; ++i)
			{
				Assert::AreEqual(*i, *exp_iter);
				++checker;
				++exp_iter;
			}
			
			Assert::AreEqual(checker, static_cast<int>(expected.length()));
			Assert::AreEqual(checker, static_cast<int>(result.length()));
		}

		TEST_METHOD(Test_Binary)
		{
			std::vector<Rule> rules;
			Rule a1("1", "0|");
			Rule a2("|0", "0||");
			Rule a3("0", "", true);
			rules.push_back(a1);
			rules.push_back(a2);
			rules.push_back(a3);
			String result = markovAlg(rules, "1001");
			String expected = "|||||||||";

			int checker = 0;
			auto exp_iter = expected.begin();
			for (auto i = expected.begin(); i < expected.end(); ++i)
			{
				Assert::AreEqual(*i, *exp_iter);
				++checker;
				++exp_iter;
			}

			Assert::AreEqual(checker, static_cast<int>(expected.length()));
			Assert::AreEqual(checker, static_cast<int>(result.length()));
		}

		TEST_METHOD(Test_Addition)
		{

			std::vector<Rule> rules;
			Rule a1("+", "", true);
			rules.push_back(a1);
			String result = markovAlg(rules, "||||+||");
			String expected = "||||||";

			int checker = 0;
			auto exp_iter = expected.begin();
			for (auto i = expected.begin(); i < expected.end(); ++i)
			{
				Assert::AreEqual(*i, *exp_iter);
				++checker;
				++exp_iter;
			}

			Assert::AreEqual(checker, static_cast<int>(expected.length()));
			Assert::AreEqual(checker, static_cast<int>(result.length()));
		}

		TEST_METHOD(Test_Exceptions)
		{
			std::vector<Rule> rules;
			Rule a1("+", "++");
			rules.push_back(a1);
			try
			{
				markovAlg(rules, "+++");
				Assert::Fail();
			}
			catch (const BadRule& A) 
			{
				A.report();
			}
		}
	};
}
