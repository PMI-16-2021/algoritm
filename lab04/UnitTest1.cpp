#include "pch.h"
#include "CppUnitTest.h"
#include "..\\Project29\hashtable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(IsEmptyTest){
			HashTable H;
			Assert::IsTrue(H.isEmpty());
			H.add(1.0, "spike");
			H.add(4.1, "frank");
			Assert::IsFalse(H.isEmpty());
		}

		TEST_METHOD(AddTest) {
			HashTable H;
			H.add(1.0, "spike");
			Assert::IsFalse(H.isEmpty());
			H.add(4.1, "frank");
			H.add(2.7, "bull");
			Assert::AreEqual(3, H.elemCount());
		}

		TEST_METHOD(PopTest) {
			HashTable H;
			H.add(1.0, "spike");
			H.pop("spike");
			Assert::IsTrue(H.isEmpty());
			H.add(4.1, "frank");
			H.add(2.7, "bull");
			H.pop("frank");
			Assert::AreEqual(1, H.elemCount());
		}

		TEST_METHOD(GetTest) {
			HashTable H;
			H.add(1.0, "spike");
			H.add(4.1, "frank");
			H.add(2.7, "bull");
			Assert::AreEqual(1.0, H.get("spike"));
			Assert::AreEqual(2.7, H.get("bull"));
		}

		TEST_METHOD(ElemCountTest) {
			HashTable H;
			H.add(1.0, "spike");
			H.pop("spike");
			Assert::AreEqual(0, H.elemCount());
			H.add(4.1, "frank");
			H.add(2.7, "bull");
			Assert::AreEqual(2, H.elemCount());
			H.pop("frank");
			Assert::AreEqual(1, H.elemCount());
		}

		TEST_METHOD(FindTest) {
			HashTable H;
			H.add(1.0, "spike");
			H.add(2.7, "bull");
			Assert::IsFalse(H.checkKey("frank"));
			Assert::IsTrue(H.checkKey("spike"));
		}
	};
}
