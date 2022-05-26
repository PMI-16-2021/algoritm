
#include "HashTable.h"

// Конструктор з параметром кількості комірокв таблиці
// Стандартне значення 20
HashTable::HashTable(int tableLength) {
    if (tableLength <= 0) {
        tableLength = 20;
    }
    array = new LinkedList[tableLength];
    length = tableLength;
}

// гешування
int HashTable::hash(std::string itemKey) {
    int value = 0;
    for (int i = 0; i < itemKey.length(); i++){
        value += itemKey[i];
    }
    return (value * itemKey.length()) % length;
}

// додаємо елемент в таблицю
void HashTable::insertItem(Item *newItem) {
    int index = hash(newItem->key);
    array[index].insertItem(newItem);
}

// видаляємо елемент за ключем
// повертає true якщо операція успішна
bool HashTable::removeItem(std::string itemKey) {
    int index = hash(itemKey);
    return array[index].removeItem(itemKey);
}

// Повертає елемент таблиці за ключем
//  nullptr - повертається, якщо такого елемента не знайдено
Item *HashTable::getItemByKey(std::string itemKey) {
    int index = hash(itemKey);
    return array[index].getItem(itemKey);
}

//метод, що друкує елементи таблиці
void HashTable::printTable() {
    std::cout << "\n\nHash Table:\n";
    for (int i = 0; i < length; i++) {
        std::cout << "Bucket " << i + 1 << ": ";
        array[i].printList();
    }
}

// метод, що повертає розмір таблиці
int HashTable::getLength() {
    return length;
}

// метод, що повертає кількість елементів в таблиці
int HashTable::getNumberOfItems() {
    int itemCount = 0;
    for (int i = 0; i < length; i++) {
        itemCount += array[i].getLength();
    }
    return itemCount;
}

// деструктор
HashTable::~HashTable() {
    delete[] array;
}
