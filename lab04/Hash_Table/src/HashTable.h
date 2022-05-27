#pragma once

#include "LinkedList.h"

class HashTable {
private:

    // змінна array є вказівником на обʼєкт LinkedList
    LinkedList *array;

    // length - розмір геш-таблиця
    int length;

    // метод гешування, що повертає місце в array
    int hash(std::string itemKey);

public:

    // Конструктор без параметрів
    // Стандартно створюється геш таблиця розміру - 20
    HashTable(int tableLength = 20);
    // метод, що додає елементи в таблицю
    void insertItem(Item *newItem);

    // метод, що видаляє елементи за ключем
    // повертає true, якщо операція успішна
    bool removeItem(std::string itemKey);

    // метод, що повертає елемент за ключем
    // якщо елемент не знайдено, то повертає nullptr
    Item *getItemByKey(std::string itemKey);

    // метод, друкує таблицю у консоль
    void printTable();

    // метод, що повертає розмір таблиці загалом
    int getLength();

    // метод, що повертає кількість елементів в таблиці
    int getNumberOfItems();

    // деструктор
    ~HashTable();
};
