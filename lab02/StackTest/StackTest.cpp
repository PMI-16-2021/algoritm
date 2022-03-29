#include "pch.h"
#include "CppUnitTest.h"
#include "../dmitru4ok/SetOfStacks.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackTest
{
	TEST_CLASS(Stack_Methods_Test)
	{
	public:
		
		TEST_METHOD(Constructors_Test)
		{
			Stack<int> A;
			Stack<char> B;
			Stack<double> C;
			Assert::IsTrue(A.empty());
			Assert::IsTrue(B.empty());
			Assert::IsTrue(C.empty());
			Stack<long> D(5);
			Assert::IsFalse(D.empty());
		}
		TEST_METHOD(Push_pop_Test)
		{
			Stack<int> A;
			A.push(3);
			Assert::AreEqual(3, A.top());
			A.push(4);
			Assert::AreEqual(4, A.pop());
			Assert::AreEqual(3, A.pop());
		}

		TEST_METHOD(Top_Test)
		{
			Stack<char> B; //create empty Stack

			try
			{
				B.top(); //trying to acess non-existing element
				Assert::Fail(); //this code must NOT be executed
			}
			catch (const char*)
			{

			}
			B.push('a');
			B.push('d');//push element
			Assert::AreEqual('d', B.top());
			Assert::AreEqual('d', B.pop());
			Assert::AreEqual('a',B.top()); //top MUST NOT remove
			Assert::IsFalse(B.empty());  
			Assert::AreEqual('a', B.pop());
			Assert::IsTrue(B.empty());
		}

		TEST_METHOD(clear_Test)
		{
			Stack<double> A(4.75);
			Assert::IsFalse(A.empty());
			Assert::AreEqual(4.75, A.top());
			A.push(5.);
			Assert::AreEqual(5., A.top());
			A.push(2.3);
			Assert::AreEqual(2.3, A.top());
			Assert::IsFalse(A.empty());
			A.clear();
			Assert::IsTrue(A.empty());	
		}

		TEST_METHOD(empty_Test)
		{
			Stack<double> A;
			Assert::IsTrue(A.empty());
			A.push(9.7);
			Assert::IsFalse(A.empty());
			Stack<double> B(5.678);
			Assert::IsFalse(B.empty());
			B.pop();
			Assert::IsTrue(B.empty());
		}

		TEST_METHOD(size_Test)
		{
			Stack<int> A;
			Assert::AreEqual(0, A.size());
			A.push(5);
			A.push(4);
			Assert::AreEqual(2, A.size());
			A.push(3);
			A.push(2);
			A.push(1);
			Assert::AreEqual(5, A.size());
			Stack<int> B(6); 
			Assert::AreEqual(1, B.size());
		}

		TEST_METHOD(emplace_Test)
		{
			Stack<int> A;
			int a = 3, b = 4;
			A.emplace(a);
			A.emplace(b);
			Assert::AreEqual(b, A.top());
			Assert::AreEqual(b, A.pop());
			Assert::AreEqual(a, A.top());
			Assert::AreEqual(a, A.pop());
		}

		TEST_METHOD(swap_Test)
		{
			Stack<int> A(5); //A
			A.push(4); //2 elems: 4, 5
			Assert::AreEqual(4, A.top());
			Assert::AreEqual(2, A.size());

			Stack<int> B(0); //B
			B.push(1); 
			B.push(2); 
			B.push(3); //4 elems: 3, 2, 1, 0
			
			Assert::AreEqual(4, B.size());
			Assert::AreEqual(3, B.top());
			A.swap(B); // A is B // B is A
			
			Assert::AreEqual( 4, B.top()); 
			Assert::AreEqual(2, B.size());

			Assert::AreEqual(3, A.top()); 
			Assert::AreEqual(4, A.size());		   
		}
	};
}
