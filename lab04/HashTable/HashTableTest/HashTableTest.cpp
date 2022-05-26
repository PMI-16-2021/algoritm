#include "pch.h"
#include "CppUnitTest.h"
#include "../HashTable/hashtable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableTest
{
	TEST_CLASS(HashTableTest)
	{
	public:
		
		TEST_METHOD(AddTest) {
			HashTable<int> HT;
			HT.add("Fr", 35);
			Assert::IsFalse(HT.isEmpty());
		}
		TEST_METHOD(PopTest) {
			HashTable<int> HT;
			HT.add("Fr", 35);
			HT.pop("Fr");
			Assert::IsTrue(HT.isEmpty());
		}
		TEST_METHOD(GetTest) {
			HashTable<int> HT;
			HT.add("Fr", 35);
			Assert::AreEqual(35, HT.get("Fr"));
		}
		TEST_METHOD(HashTest) {
			HashTable<int> HT;
			HT.add("Fr", 35);
			HT.add("Se", 7);
			Assert::AreEqual(0, HT._hash("Fr"));
		}
	};
}
