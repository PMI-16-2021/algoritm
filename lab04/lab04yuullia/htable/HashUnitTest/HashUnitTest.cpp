#include "pch.h"
#include "CppUnitTest.h"
#include "..//htable/hash.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashUnitTest
{
	TEST_CLASS(HashUnitTest)
	{
	public:

        TEST_METHOD(TestConstructor)
        {
            HashTable ht;
            Assert::IsTrue(ht.isEmpty());

            HashTable ht1("a", 1);
            Assert::IsFalse(ht1.isEmpty());
            Assert::AreEqual(ht1.elemCount(), 1);
            Assert::AreEqual(ht1.get("a"), 1);
        }

		TEST_METHOD(TestAdd)
		{
            HashTable ht;
            ht.add("a", 1);
            Assert::IsFalse(ht.isEmpty());
            Assert::AreEqual(ht.elemCount(), 1);
            Assert::AreEqual(ht.get("a"), 1);
		}

        TEST_METHOD(TestGet)
		{
            HashTable ht;
            Assert::AreEqual(ht.get(""), 0);

            HashTable ht1("a", 1);
            Assert::AreEqual(ht1.get("a"), 1);
		}

        TEST_METHOD(TestPop)
		{
            HashTable ht("a", 1);
            ht.pop("a");
            Assert::AreNotEqual(ht.get("a"), 1);
            Assert::IsTrue(ht.isEmpty());
		}
        
       TEST_METHOD(TestElemCount)
		{
            HashTable ht;
            Assert::AreEqual(ht.elemCount(), 0);
            HashTable ht1("a", 1);
            Assert::AreEqual(ht1.elemCount(), 1);
		}
        
        TEST_METHOD(TestIsEmpty)
		{
            HashTable ht;
            Assert::IsTrue(ht.isEmpty());
            ht.add("a", 1);
            Assert::IsFalse(ht.isEmpty());
		}
	};
}
