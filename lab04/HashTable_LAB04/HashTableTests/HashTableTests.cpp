#include "pch.h"
#include "CppUnitTest.h"
#include "..//HashTable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestHashTable
{
	TEST_CLASS(UnitTestHashTable)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			HashTable table;
			Row obj1("Yatskiv", "Peter", 71.);
			string person = "Yatskiv";
			Assert::AreEqual(obj1.surname, person);
			person = "Peter";
			Assert::AreEqual(obj1.name, person);
			Assert::AreEqual(obj1.mark, 71.);
		}

		TEST_METHOD(TestMethodHash)
		{
			HashTable table(3);
			Row obj1("Peter", "Ostap", 84.);
			table.add(obj1);
			int index = hash(obj1.surname, 3);
			Assert::AreEqual(index, 2);
		}

		TEST_METHOD(TestMethodFind)
		{
			HashTable table(3);
			Row obj3("Nanivska", "Nadia", 96.);
			table.add(obj3);
			Assert::AreEqual(table.sizeOf(), 3);
			int index = table.find("Nanivska");
			Assert::AreEqual(index, 2);
			Assert::IsFalse(table.isEmpty());

		}

		TEST_METHOD(TestMethodClear)
		{
			HashTable table(1);
			Row obj3("Yatskiv", "Vitalik", 96.);
			table.add(obj3);
			Assert::AreEqual(table.sizeOf(), 1);
			table.clear();
			Assert::IsTrue(table.isEmpty());
			Assert::AreEqual(table.sizeOf(), 0);
		}

		TEST_METHOD(TestMethodIsEmpty)
		{
			HashTable table;
			Assert::IsTrue(table.isEmpty());
		}
	};
}
