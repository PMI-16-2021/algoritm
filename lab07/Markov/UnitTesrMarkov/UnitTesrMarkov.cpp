#include "pch.h"
#include "CppUnitTest.h"
#include "../Markov/StringM.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesrMarkov
{
	TEST_CLASS(UnitTesrMarkov)
	{
	public:
		
		TEST_METHOD(TestMarkov1) {
			std::vector<std::pair<String, String>> NAM = { { "x0","0x" }, { "x1","1x" }, { "x","y" }, { "0y",".1" }, { "1y","y0" }, { "y",".1" }, { "","x" } };
			String res("11");
			res.MarkovAlgorithm(NAM);
			String exp("100");
		
			Assert::AreEqual(std::string(exp.getStr()), std::string(res.getStr()));
		}

		TEST_METHOD(TestMarkov2) {
			std::vector<std::pair<String, String>> NAM = { {"+", ""} };
			String res("||||+||");
			res.MarkovAlgorithm(NAM);
			String exp("||||||");

			Assert::AreEqual(std::string(exp.getStr()), std::string(res.getStr()));
		}
		TEST_METHOD(TestMarkov3) {
			std::vector<std::pair<String, String>> NAM = { {"1", "0|"}, {"|0", "0||"}, {"0", ""}};
			String res("1001");
			res.MarkovAlgorithm(NAM);
			String exp("|||||||||");

			Assert::AreEqual(std::string(exp.getStr()), std::string(res.getStr()));
		}

	};
}
