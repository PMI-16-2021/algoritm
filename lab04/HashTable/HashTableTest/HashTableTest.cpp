#include "pch.h"
#include "CppUnitTest.h"
#include "../HashTable/hashtable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableTest
{
	TEST_CLASS(HashTableTest)
	{
	public:
		
		TEST_METHOD(AddandIsFalseTest) {
			HashTable<int> HT;
			HT.add("Fr", 35);
			Assert::IsFalse(HT.IsEmpty());
			Assert::AreEqual(35, HT.get("Fr"));
		}
		TEST_METHOD(PopTest) {
			HashTable<int> HT;
			HT.add("Fr", 181);
			HT.add("Rf", 120);
			HT.add("Se", 56);
			HT.pop("Rf");
			Assert::IsFalse(HT.find("Rf"));
		}
		TEST_METHOD(GetTest) {
			HashTable<int> HT;
			HT.add("Fr", 35);
			Assert::AreEqual(35, HT.get("Fr"));
		}
		TEST_METHOD(FindTest) {
			HashTable<int> HT;
			HT.add("Fr", 35);
			HT.add("Se", 7);
			Assert::IsTrue(HT.find("Fr"));
			Assert::IsTrue(HT.find("Se"));
		}
	};
}
