#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab04/hashTable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest4
{
	TEST_CLASS(UnitTest4)
	{
	public:
		
        TEST_METHOD(TestCtors)
        {
            HashTable table;
            Assert::AreNotEqual(table[21].c_str(), "");
            Assert::AreEqual(table[21].c_str(), "null");
        }

        TEST_METHOD(TestHash)
        {
            HashTable table;

            int index = table.hash(16);
            table.insert(16, "16(0) data");
            Assert::AreNotEqual(index, table.hash(17));

            Assert::AreEqual(table.hash(16), (index + 1) % table.capacity());
            table.insert(16, "16(1) data");

            Assert::AreEqual(table.hash(16), (index + 6) % table.capacity());

            int index2 = table.hash(2);
            table.insert(2, "2 data");
            Assert::AreNotEqual(index, table.hash(20));
        }

        TEST_METHOD(TestFind)
        {
            HashTable table;

            int index1 = table.hash(16);
            table.insert(16, "16 data");

            int index2 = table.hash(5);
            table.insert(5, "5 data");

            int index3 = table.hash(21);
            table.insert(21, "21 data");

            Assert::AreNotEqual(index1, table.find(8));
            Assert::AreNotEqual(index2, table.find(8));
            Assert::AreNotEqual(index3, table.find(8));

            Assert::AreEqual(index1, table.find(16));
            Assert::AreEqual(index2, table.find(5));
            Assert::AreEqual(index3, table.find(21));
        }

        TEST_METHOD(TestIsEmpty)
        {
            HashTable table;
            Assert::AreEqual(table.isEmpty(), true);
            table.insert(123, "123 data");
            Assert::AreNotEqual(table.isEmpty(), true);
        }

        TEST_METHOD(TestInsert)
        {
            HashTable table;
            Assert::AreEqual(table.insert(1, "1 data"), false);
            Assert::AreEqual(table.size(), 1);

            int colisions = 0;
            for (int i = 2; i < 11; i++)
            {
                colisions += table.insert(i * i, "i^2 data");
                Assert::AreEqual(table.size(), i);
            }

            Logger::WriteMessage("hash colisions: ");
            std::string str = std::to_string(colisions);
            char const* colisions_char = str.c_str();
            Logger::WriteMessage(colisions_char);
        }

        TEST_METHOD(TestErase)
        {
            HashTable table;

            table.insert(16, "16 data");
            table.insert(5, "5 data");
            table.insert(21, "21 data");
            table.insert(17, "17 data");
            table.insert(299, "299 data");
            Assert::AreEqual(table.size(), 5);

            table.erase(21);
            Assert::AreEqual(table.size(), 4);
            Assert::AreEqual(table[21].c_str(), "null");

            table.erase(16);
            Assert::AreEqual(table.size(), 3);
            Assert::AreEqual(table[16].c_str(), "null");

            try
            {
                table.erase(7);
            }
            catch (const std::invalid_argument& exc)
            {
                const char* what = exc.what();
                Logger::WriteMessage("Exception handled: ");
                Logger::WriteMessage(what);
            }
        }

        TEST_METHOD(TestIndexingOperator)
        {
            HashTable table;

            table.insert(16, "16 data");
            table.insert(5, "5 data");
            table.insert(21, "21 data");
            table.insert(17, "17 data");
            table.insert(299, "299 data");

            table[17] = "modified 17 data";
            Assert::AreEqual(table[17].c_str(), "modified 17 data");

            std::string& data16 = table[16];
            data16 = "modified 16 data";
            Assert::AreEqual(table[16].c_str(), "modified 16 data");

            std::string data5 = table[5];
            Assert::AreEqual(data5.c_str(), "5 data");
        }

        TEST_METHOD(TestKeyColision)
        {
            HashTable table(5);

            table.insert(16, "16 data");
            table.insert(5, "5 data");
            table.insert(21, "21 data");
            table.insert(17, "17 data");
            table.insert(299, "299 data");

            table.insert(5, "5 data");
            table.insert(21, "21 data");

            Assert::AreEqual(table.key_colision(16), 1);
            Assert::AreEqual(table.key_colision(17), 1);
            Assert::AreEqual(table.key_colision(299), 1);

            Assert::AreEqual(table.key_colision(5), 2);
            Assert::AreEqual(table.key_colision(21), 2);
            Assert::AreEqual(table.key_colision(333), 0);
        }
	};
}
