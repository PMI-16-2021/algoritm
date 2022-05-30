#include "pch.h"
#include "CppUnitTest.h"
#include "..//Tree/tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTree
{
	TEST_CLASS(UnitTestTree)
	{
	public:
		
		TEST_METHOD(insertTest)
		{
			Tree<int> tree;
			tree.insert(1);
			tree.insert(2);
			Assert::IsTrue(tree.find(2));
			Assert::IsFalse(tree.find(3));
		}
		TEST_METHOD(findTest)
		{
			Tree<int> tree;
			Assert::IsFalse(tree.find(1));
			tree.insert(1);
			Assert::IsTrue(tree.find(1));

		}
		TEST_METHOD(removeTest)
		{
			Tree<int> tree;
			tree.insert(1);
			tree.insert(2);
			tree.remove(1);
			Assert::IsFalse(tree.find(1));
		}
	};
}
