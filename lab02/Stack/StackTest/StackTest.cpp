#include "pch.h"
#include "CppUnitTest.h"
#include "../Stack/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackTest
{
	TEST_CLASS(StackTest)
	{
	public:
		
		TEST_METHOD(ConstructorsTest){
			Stack First;
			Assert::IsTrue(First.isEmpty());
			
			Stack Second(3);
			Assert::IsFalse(Second.isEmpty());
		}

		TEST_METHOD(TopSTest) {
			Stack First;
			First.push(1);
			Assert::AreEqual(1, First.topS());
			First.push(2);
			Assert::AreEqual(2, First.topS());
		}
		TEST_METHOD(PushTest) {
			Stack First;
			First.push(1);
			Assert::AreEqual(1, First.topS());
			First.push(2);
			Assert::AreEqual(2, First.topS());
		}
		TEST_METHOD(PopTest) {
			Stack First;
			First.push(1);
			First.pop();
			Assert::IsTrue(First.isEmpty());
		}
		TEST_METHOD(EmplaceTest) {
			Stack First;
			First.push(1);
			Assert::AreEqual(1, First.topS());
			First.push(2);
			Assert::AreEqual(2, First.topS());
		}
		TEST_METHOD(SizeTest) {
			Stack First;
			Assert::AreEqual(0, First.size());
			First.push(1);
			Assert::AreEqual(1, First.size());

			Stack Second(3);
			Assert::AreEqual(1, Second.size());
		}
		TEST_METHOD(EmptyTest) {
			Stack First;
			First.push(1);
			First.push(2);
			First.empty();
			Assert::IsTrue(First.isEmpty());
		}
		TEST_METHOD(SwapTest) {
			Stack First(1);
			First.push(2);

			Stack Second(3);
			Second.push(4);
			Second.push(5);

			First.swap(&Second);

			Assert::AreEqual(5, First.topS());
			Assert::AreEqual(2, Second.topS());
		}
	};
}
