#include "pch.h"
#include "CppUnitTest.h"
#include "../HashTable/HashTable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TableTesting
{
	TEST_CLASS(TableTesting)
	{
	public:
		
		TEST_METHOD(add_Test)
		{
			HashTable<int> A; 
			TableElem<int> var;
			Assert::IsFalse(A.get("element", var));

			A.add("element", 5);
			Assert::IsTrue(A.get("element", var));
			string el = "element";
			Assert::AreEqual(5, var.value);
			Assert::AreEqual(el, var.key);

			A.add("element", 10); //dublicate key can not be added
			Assert::IsTrue(A.get("element", var));
			Assert::AreNotEqual(10, var.value);

			A.pop("element");
			Assert::IsFalse(A.get("element", var));
		}

		TEST_METHOD(get_Test)
		{
			HashTable<int> B(50);
			TableElem<int> var;
			string smth = "something";
			Assert::IsFalse(B.get("something", var));
			B.add("something", 10);
			Assert::IsTrue(B.get("something", var));
			Assert::AreEqual(10, var.value);
			Assert::AreEqual(smth, var.key);
			B.pop("something");
			Assert::IsFalse(B.get("something", var));
		}

		TEST_METHOD(pop_Test)
		{
			
			HashTable<int> B(50);
			TableElem<int> var;
			B.add("Yura", 18);
			Assert::IsFalse(B.get("me", var));
			Assert::IsTrue(B.get("Yura", var));
			string name = "Yura";
			Assert::AreEqual(name, var.key);
			Assert::AreEqual(18, var.value);

		}

		TEST_METHOD(values_Test)
		{
			HashTable<int> B(50);
			
			pair<TableElem<int>*, int> arr_holder = B.values();
			Assert::IsNull(arr_holder.first);
			Assert::AreEqual(-1, arr_holder.second);
			B.add("2", 2);               
			arr_holder = B.values();
			Assert::IsNotNull(arr_holder.first);
			Assert::AreEqual(1, arr_holder.second);

			Assert::AreEqual(2, arr_holder.first[0].value); //hash from "2" is (50 % 50) = 0
		}
	};
}
