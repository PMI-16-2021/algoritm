#include <HashTable.h>
#include <gtest/gtest.h>

TEST(HashTableTest, CreationTest){
    HashTable hashTable;
    Item *someItem = new Item{"Petriv", 100};
    hashTable.insertItem(someItem);
    Item *newItem =  hashTable.getItemByKey("Petriv");

    EXPECT_EQ(newItem->getValue(), 100);
}

TEST(HashTableTest, getHashTableLengthTest){
    HashTable hashTable(30);
    EXPECT_EQ(hashTable.getLength(), 30);
}

TEST(HashTableTest, getAmountOfElementsInHashTableTest){
    HashTable hashTable;
    EXPECT_EQ(hashTable.getNumberOfItems(), 0);
    Item *someItem = new Item{"Petriv", 100};
    hashTable.insertItem(someItem);
    EXPECT_EQ(hashTable.getNumberOfItems(), 1);
}

TEST(HashTableTest, getItemByKeyTest){
    Item *A = new Item{"Petriv", 52, nullptr};
    Item *B = new Item{"Ivankiv", 31, nullptr};


    HashTable hashTable;

    hashTable.insertItem(A);
    hashTable.insertItem(B);

    EXPECT_EQ(hashTable.getItemByKey("Petriv")->getValue(), A->getValue());
    EXPECT_EQ(hashTable.getItemByKey("Ivankiv")->getValue(), B->getValue());
    EXPECT_EQ(hashTable.getItemByKey("Kyslytsia"), nullptr);
}
