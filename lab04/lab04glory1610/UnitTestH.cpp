#include "pch.h"
#include "CppUnitTest.h"
#include "..//Lab_11/HashT.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestH
{
	TEST_CLASS(UnitTestH)
	{
	public:
		
		TEST_METHOD(TestAdd)
		{
			HashTable<string, int>* h = new HashTable<string, int>;
			h->add("Apple", 5);
			h->add("Pear", 15);
			h->add("Peach", 1);
			Assert::AreEqual(1, h->get("Peach"));
		}
		TEST_METHOD(TestPop)
		{
			HashTable<string, int>* a = new HashTable<string, int>;
			a->add("Apple", 5);
			a->add("Pear", 15);
			a->add("Peach", 1);
			Assert::AreEqual(3, a->sizeofTable());
			a->pop("Pear");
			Assert::AreEqual(2, a->sizeofTable());
			Assert::IsFalse(a->get("Pear"));
		}
		TEST_METHOD(TestGet)
		{
			HashTable<string, int>* m = new HashTable<string, int>;
			m->add("Cherry", 19);
			m->add("Blueberry", 11);
			m->add("Blackberry", 9);
			m->add("Grape", 7);
			Assert::AreEqual(7, m->get("Grape"));
		}
		TEST_METHOD(TestHash)
		{
			HashTable<string, int>* k = new HashTable<string, int>;
			k->add("Cherry", 19);
			k->add("Blueberry", 11);
			Assert::AreEqual(9, k->hash("Blueberry"));
		}
		TEST_METHOD(TestSize)
		{
			HashTable<string, int>* l = new HashTable<string, int>;
			l->add("Cherry", 19);
			l->add("Blueberry", 11);
			Assert::AreEqual(2, l->sizeofTable());
		}
	};
}
