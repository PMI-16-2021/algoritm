#include "pch.h"
#include "CppUnitTest.h"
#include "..\Project1\has.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
	public:
		
		TEST_METHOD(AddTest) {
			HashTable<int> temp;
			std::string st = "serg";
			temp.add(st, 1);
			Assert::AreEqual(1, temp.get("serg"));
		}
		TEST_METHOD(PopTest) {
			HashTable<int> temp;
			std::string st = "serg";
			temp.add(st, 35);
			temp.pop(st);
			Assert::AreEqual(0, temp.get("serg"));
		}
		TEST_METHOD(GetTest) {
			HashTable<int> temp;
			std::string st = "serg";
			temp.add(st, 35);
			Assert::AreEqual(35, temp.get("serg"));
		}
	};
}
