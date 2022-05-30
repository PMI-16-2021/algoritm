#include "pch.h"
#include "CppUnitTest.h"
#include "..//Hash/hash.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesthash
{
	TEST_CLASS(UnitTesthash)
	{
	public:
		
		TEST_METHOD(empty)
		{
			HashTable ht;
			Assert::IsTrue(ht.isEmpty());
			ht.add(5, "bubble_gum");
			Assert::IsFalse(ht.isEmpty());
		}
		TEST_METHOD(size)
		{
			HashTable ht;
			ht.add(5, "bubble_gum");
			ht.add(7, "fish_dori");
			ht.add(10, "dori");
			ht.add(3, "bubble_gum");
			Assert::AreEqual(4, ht.size());
		}
		TEST_METHOD(pop)
		{
			HashTable ht;
			ht.add(5, "bubble_gum");
			ht.add(7, "fish_dori");
			ht.add(10, "dori");
			ht.add(3, "bubble_gum");
			Assert::AreEqual(4, ht.size());
			ht.pop("bubble_gum");
			ht.pop("bubble_gum");
			Assert::AreEqual(2, ht.size());
		}
		TEST_METHOD(get)
		{
			HashTable ht;
			ht.add(7, "fish_dori");
			ht.add(10, "dori");
			ht.add(3, "bubble_gum");
			Assert::AreEqual(3,ht.get("bubble_gum"));
			Assert::AreEqual(10, ht.get("dori"));
			Assert::AreEqual(7, ht.get("fish_dori"));
		}
	};
}
