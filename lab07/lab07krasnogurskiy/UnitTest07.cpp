#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab07/markov.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest07
{
	TEST_CLASS(UnitTest07)
	{
	public:

		TEST_METHOD(TestTerminal)
		{
			std::vector<Rule>rules;
			rules.emplace_back("|b", "ba|", false);
			rules.emplace_back("ab", "ba", false);
			rules.emplace_back("b", "", false);
			rules.emplace_back("*|", "b*", false);
			rules.emplace_back("*", "c", false);
			rules.emplace_back("|c", "c", false);
			rules.emplace_back("ac", "c|", false);
			rules.emplace_back("c", "terminalend(c)", true);

			std::string text = "b***";

			Assert::AreEqual(std::string("terminalend(c)cc"), markovAlgorithm(rules, text));

			auto rule5iter = rules.begin();
			std::advance(rule5iter, 4);
			std::swap(*rule5iter, *(--rules.end()));

			Assert::AreEqual(std::string("terminalend(c)**"), markovAlgorithm(rules, text));
		}
		TEST_METHOD(TestNoTerminal)
		{
			std::vector<Rule>rules;
			rules.emplace_back("|b", "ba|", false);
			rules.emplace_back("ab", "ba", false);
			rules.emplace_back("b", "", false);
			rules.emplace_back("*|", "b*", false);
			rules.emplace_back("*", "c", false);
			rules.emplace_back("|c", "c", false);
			rules.emplace_back("ac", "c|", false);
			rules.emplace_back("c", "", true);

			std::string text = "|b*|";

			Assert::AreEqual(std::string("||"), markovAlgorithm(rules, text));
		}

		TEST_METHOD(TestNoRules)
		{
			std::vector<Rule>rules;
			rules.emplace_back("|b", "ba|", false);
			rules.emplace_back("ab", "ba", false);
			rules.emplace_back("b", "", false);
			rules.emplace_back("*|", "b*", false);
			rules.emplace_back("*", "c", false);
			rules.emplace_back("|c", "c", false);
			rules.emplace_back("ac", "c|", false);
			rules.emplace_back("c", "terminalend(c)", true);

			std::string text = "kl;kl;kl;kklu8";

			Assert::AreEqual(std::string("kl;kl;kl;kklu8"), markovAlgorithm(rules, text));
		}
	};
}
