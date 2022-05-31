#include "pch.h"
#include "CppUnitTest.h"
#include"..\hash_table.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableTest
{
	TEST_CLASS(HashTableTest)
	{
	public:

		TEST_METHOD(Add_GetTest) {
			HashTable<int> H;
			HashTableNode<int> example("abc", 20);
			HashTableNode<int> example1("qwe", 15);
			HashTableNode<int> example2("asd", 10);
			HashTableNode<int> example3("zxc", 5);
			H.Add(example);
			H.Add(example1);
			H.Add(example2);
			H.Add(example3);
			Assert::AreEqual(20, H.Get("abc"));
			Assert::AreEqual(15, H.Get("qwe"));
			Assert::AreEqual(10, H.Get("asd"));
			Assert::AreEqual(5, H.Get("zxc"));
			try {
				H.Get("qqq");
				Assert::Fail;
			}
			catch (const char* msg) {
				std::cerr << msg;
			}
		}
		TEST_METHOD(HashTest) {
			HashTable<int> H;
			std::string example = "abc";
			Assert::AreEqual(4, H.Hash(example));
		}

		TEST_METHOD(PopTest) {
			HashTable<int> H;
			HashTableNode<int> example("abc", 20);
			HashTableNode<int> example1("qwe", 15);
			HashTableNode<int> example2("asd", 10);
			HashTableNode<int> example3("zxc", 5);
			H.Add(example);
			H.Add(example1);
			H.Add(example2);
			H.Add(example3);
			H.Pop("abc");
			try {
				H.Get("abc");
				Assert::Fail;
			}
			catch (const char* msg) {
				std::cerr << msg;
			}
		}

	
	};
}
