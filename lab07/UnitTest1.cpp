#include "pch.h"
#include "CppUnitTest.h"
#include "..\\markov\markovAlgorithm.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(GetLengthTest) {
			String word1 = "arolf";
			int result1 = word1.getLength();
			Assert::AreEqual(result1, 5);
			String word2 = "zxc leon";
			int result2 = word2.getLength();
			Assert::AreEqual(result2, 8);
			String word3 = "";
			int result3 = word3.getLength();
			Assert::AreEqual(result3, 0);
		}
		TEST_METHOD(FindTest) {
			String text = "the tastiest fish is salmon";
			Assert::AreEqual(text.find("fish"), 13);
			Assert::AreEqual(text.find("tastiest"), 4);
			Assert::AreEqual(text.find("are"), -1);
		}
		TEST_METHOD(ReplaceTest) {
			String text = "the tastiest fish is salmon";
			text.replace("salmon", "perch");
			String result = "the tastiest fish is perch";
			for (int i = 0; i < text.getLength(); ++i) {
				Assert::AreEqual(text[i], result[i]);
			}
		}
		TEST_METHOD(MarkovAlg1Test) {
			std::vector<Rule> rules;
			Rule r1("-", "");
			Rule r2("*", "");
			rules.push_back(r1);
			rules.push_back(r2);
			String result = markovAlgorithm(rules, "||-|*|||");
			String expected = "||||||";
			for (int i = 0; i < result.getLength(); ++i) {
				Assert::AreEqual(result[i], expected[i]);
			}
		}
		TEST_METHOD(MarkovAlg2Test) {
			std::vector<Rule> rules;
			Rule r1("1", "|0");
			Rule r2("0", "");
			Rule r3("", "", true);
			rules.push_back(r1);
			rules.push_back(r2);
			rules.push_back(r3);
			String result = markovAlgorithm(rules, "0111");
			String expected = "|||";
			for (int i = 0; i < result.getLength(); ++i) {
				Assert::AreEqual(result[i], expected[i]);
			}
		}
		TEST_METHOD(MarkovAlg3Test) {
			std::vector<Rule> rules;
			Rule r1("S", "salmon");
			Rule r2("G", "dog");
			Rule r3("J", "fish");
			rules.push_back(r1);
			rules.push_back(r2);
			rules.push_back(r3);
			String result = markovAlgorithm(rules, "the tastiest J is S");
			String expected = "the tastiest fish is salmon";
			for (int i = 0; i < result.getLength(); ++i) {
				Assert::AreEqual(result[i], expected[i]);
			}
		}
		TEST_METHOD(comparisonOperator) {
			String word1 = "abolf";
			String word2 = "arolf";
			String word3 = "abolf";
			Assert::IsFalse(word1 == word2);
			Assert::IsTrue(word1 == word3);
		}
	};
}
