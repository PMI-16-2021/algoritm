#include "pch.h"
#include "CppUnitTest.h"
#include "..//MarkovAlgorithm/string.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MarkovAlgorithmTest {

	TEST_CLASS(MarkovAlgorithmTest) {

	public:
		// String Test
		TEST_METHOD(LengthTest) {
			String line = "This is example";
			int result = line.lenght();
			Assert::AreEqual(result, 15);
			String empty = "";
			int res = empty.lenght();
			Assert::AreEqual(res, 0);
		}
		TEST_METHOD(FindTest) {
			String line = "This first example";
			Assert::AreEqual(line.Find("first"), 5);
			Assert::AreEqual(line.Find("the"), -1);
		}
		TEST_METHOD(EraceTest) {
			String line = "This first example";
			line.Erase(5, 5);
			String result = "This  example";
			for (int i = 0; i < line.lenght(); ++i) {
				Assert::AreEqual(line[i], result[i]);
			}
		}
		TEST_METHOD(InsertTest) {
			String line = "This is example";
			line.Insert(8, "first ");
			String result = "This is first example";
			for (int i = 0; i < line.lenght(); ++i) {
				Assert::AreEqual(line[i], result[i]);
			}
		}
		TEST_METHOD(ReplaceTest) {
			String line = "This first example";
			line.Replace("first", "second");
			String result = "This second example";
			for (int i = 0; i < line.lenght(); ++i) {
				Assert::AreEqual(line[i], result[i]);
			}
		}
		// Markov Test
		TEST_METHOD(UnaryMultiplicationTest) {
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
			String result = Markov(rules, "|*||");
			String right = "||";
			for (int i = 0; i < result.lenght(); ++i) {
				Assert::AreEqual(result[i], right[i]);
			}
		}
		TEST_METHOD(BinaryTest) {
			std::vector<Rule> rules;
			Rule a1("1", "0|");
			Rule a2("|0", "0||");
			Rule a3("0", "");
			rules.push_back(a1);
			rules.push_back(a2);
			rules.push_back(a3);
			String result = Markov(rules, "101");
			String right = "|||||";
			for (int i = 0; i < result.lenght(); ++i) {
				Assert::AreEqual(result[i], right[i]);
			}
		}
		TEST_METHOD(AdditionTest) {
			std::vector<Rule> rules;
			Rule a1("+", "");
			rules.push_back(a1);
			String result = Markov(rules, "||+|||");
			String right = "|||||";
			for (int i = 0; i < result.lenght(); ++i) {
				Assert::AreEqual(result[i], right[i]);
			}
		}
	};
}
