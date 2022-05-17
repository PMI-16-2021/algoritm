#include "pch.h"
#include "CppUnitTest.h"
#include "..//HashTable/hash_table.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HTableTest {
	TEST_CLASS(HTableTest) {
	public:
		TEST_METHOD(GetTest) {
			HashTable<int> H1;
			H1.Add("Ferrero Rocher", 181);
			Assert::AreEqual(181, H1.Get("Ferrero Rocher"));
		}
		TEST_METHOD(AddTest) {
			HashTable<int> H1;
			H1.Add("Ferrero Rocher", 181);
			H1.Add("Raffaello", 120);
			Assert::IsFalse(H1.IsEmpty());
			Assert::IsTrue(H1.Find("Ferrero Rocher"));
			Assert::AreEqual(120, H1.Get("Raffaello"));
		}
		TEST_METHOD(IsEmptyTest) {
			HashTable<int> H1;
			Assert::IsTrue(H1.IsEmpty());
			H1.Add("Ferrero Rocher", 181);
			H1.Add("Raffaello", 120);
			Assert::IsFalse(H1.IsEmpty());
		}
		TEST_METHOD(SizeTest) {
			HashTable<int> H1;
			H1.Add("Ferrero Rocher", 181);
			H1.Add("Raffaello", 120);
			H1.Add("Sharm", 56);
			Assert::AreEqual(3, H1.Size());
		}
		TEST_METHOD(PopTest) {
			HashTable<int> H1;
			H1.Add("Ferrero Rocher", 181);
			H1.Add("Raffaello", 120);
			H1.Add("Sharm", 56);
			H1.Pop("Raffaello");
			Assert::IsFalse(H1.Find("Raffaello"));
		}
		TEST_METHOD(FindTest) {
			HashTable<int> H1;
			H1.Add("Ferrero Rocher", 181);
			H1.Add("Raffaello", 120);
			Assert::IsTrue(H1.Find("Ferrero Rocher"));
			Assert::IsFalse(H1.Find("Sharm"));
		}
	};
}
