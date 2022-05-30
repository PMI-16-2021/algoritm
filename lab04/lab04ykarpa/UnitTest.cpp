#include "pch.h"
#include "CppUnitTest.h"
#include "..//лр4/hashTable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(HashTableTest) {
	public:
		TEST_METHOD(getHashTest) {
			TableElement t1(1, true, 'c', 3.2);
			TableElement t2(2, true, 'd', 4.3);
			HashTable hashtbl;
			hashtbl.addRow(t1);
			hashtbl.addRow(t2);
			Assert::AreEqual(hashtbl.get_col_2_by_index(hashtbl.getHash(1)), 'c');
		}
		TEST_METHOD(addRowTest) {
			TableElement t1(1, true, 'c', 3.2);
			TableElement t2(2, true, 'd', 4.3);
			HashTable smp;
			smp.addRow(t1);
			smp.addRow(t2);
			Assert::AreEqual(smp.get_col_1_by_index(smp.getHash(1)), true);
		}
		TEST_METHOD(findByKeyTest) {
			TableElement t1(7, true, 'h', 8.29);
			TableElement t2(223, true, 'f', 33.256);
			HashTable smp;
			smp.addRow(t1);
			smp.addRow(t2);
			Assert::IsTrue(smp.findByKey(7, t1));
		}
		TEST_METHOD(Test_get_hash) {
			TableElement t1(5, true, 'k', 5.6);
			HashTable smp;
			smp.addRow(t1);
			Assert::AreEqual((int)smp.getHash(5), 5);
		}

		TEST_METHOD(eraseByKeyTest) {
			TableElement t1(1, true, 'c', 3.2);
			TableElement t2(3, true, 'd', 4.3);
			TableElement t3(5, true, 'k', 5.6);
			TableElement t4(7, true, 'h', 8.29);
			TableElement t5(223, true, 'f', 33.256);
			HashTable smp;
			smp.addRow(t1);
			smp.addRow(t2);
			smp.addRow(t3);
			smp.addRow(t4);
			smp.addRow(t5);
			smp.eraseByKey(5);
			Assert::AreEqual(smp.get_col_3_by_index(smp.getHash(0)), 3.14159);
		}
		TEST_METHOD(Test_get_col1_by_index) {
			TableElement t1(7, true, 'h', 8.29);
			TableElement t2(23, false, 't', 6.93);
			HashTable smp;
			smp.addRow(t1);
			smp.addRow(t2);
			Assert::AreEqual(smp.get_col_1_by_index(smp.getHash(7)), true);
			Assert::AreNotEqual(smp.get_col_1_by_index(smp.getHash(23)), true);
		}
		TEST_METHOD(Test_get_col2_by_index)	{
			TableElement t1(7, true, 'h', 8.29);
			TableElement t2(23, false, 't', 6.93);
			HashTable smp;
			smp.addRow(t1);
			smp.addRow(t2);
			Assert::AreEqual(smp.get_col_2_by_index(smp.getHash(7)), 'h');
			Assert::AreNotEqual(smp.get_col_2_by_index(smp.getHash(23)), 'h');
		}
		TEST_METHOD(Test_get_col3_by_index)	{
			TableElement t1(7, true, 'h', 8.29);
			TableElement t2(23, false, 't', 6.93);
			HashTable smp;
			smp.addRow(t1);
			smp.addRow(t2);
			Assert::AreEqual(smp.get_col_3_by_index(smp.getHash(7)), 8.29);
			Assert::AreNotEqual(smp.get_col_3_by_index(smp.getHash(23)), 5.46);
		}
		TEST_METHOD(Test_table_size) {
			TableElement t1(7, true, 'h', 8.29);
			TableElement t2(23, false, 't', 6.93);
			TableElement t3(34, false, 't', 6.93);
			TableElement t4(56, false, 't', 6.93);
			HashTable smp;
			smp.addRow(t1);
			smp.addRow(t2);
			Assert::AreEqual(smp.tableSize(), 2);
			smp.addRow(t3);
			smp.addRow(t4);
			Assert::AreEqual(smp.tableSize(), 4);
		}
		TEST_METHOD(TestIsFull) {
			TableElement t1(7, true, 'h', 8.29);
			TableElement t2(23, false, 't', 6.93);
			HashTable smp;
			Assert::IsFalse(smp.isFull());
		}
		TEST_METHOD(TestIsEmpty) {
			TableElement t1(7, true, 'h', 8.29);
			TableElement t2(23, false, 't', 6.93);
			HashTable smp;
			smp.eraseByKey(7);
			smp.eraseByKey(23);
			Assert::IsTrue(smp.isEmpty());
		}
		TEST_METHOD(TestSubstituteByKey) {
			TableElement t1(1, true, 'h', 8.29);
			TableElement t2(56, true, 'e', 7.08);
			TableElement t5(56, false, 't', 6.93);
			HashTable smp;
			smp.addRow(t1);
			smp.addRow(t2);
			smp.substituteByKey(56, t5);
			Assert::AreEqual(smp.get_col_3_by_index(smp.getHash(56)), 6.93);
		}
		TEST_METHOD(TestCollision) {
			TableElement t1(1, true, 'h', 8.29);
			TableElement t2(56, true, 'e', 7.08);
			TableElement t3(55, false, 't', 6.786);
			TableElement t4(34, true, 'h', 9.01);
			TableElement t5(65, false, 'o', 3.63);
			HashTable smp;
			smp.addRow(t1);
			smp.addRow(t2);
			smp.addRow(t3);
			smp.addRow(t4);
			smp.addRow(t5);
			Assert::AreEqual(smp.get_col_3_by_index(7), 3.63);
		}
	};
}