#include "pch.h"
#include "CppUnitTest.h"
#include "..\string_markov.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringMarkovTest
{
	TEST_CLASS(StringMarkovTest)
	{
	public:
		
		TEST_METHOD(LengthTest) {
			String line = "This is example";
			int result = line.Lenght();
			Assert::AreEqual(result, 15);
			String empty = "";
			int res = empty.Lenght();
			Assert::AreEqual(res, 0);
		}
	};
}
