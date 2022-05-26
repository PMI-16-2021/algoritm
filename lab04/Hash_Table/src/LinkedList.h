#pragma once
#include <iostream>
#include <string>

//структура, item, з ключем і вказівником на наступний item
struct Item {
    std::string key;
    int value;
    Item *next = nullptr;

    int getValue() const;


};


class LinkedList {
private:
    // вказівник на початок LinkedList
    Item *head;

    // кількість елементів Item (Nodes)
    int length;

public:
    // Конструктор за замовчуванням
    // Створює head* і задає розмір 0
    LinkedList();

    // Inserts an item at the end of the list.
    void insertItem(Item *newItem);

    // видаляє Item, за ключем
    // повертає true, якщо операція успішна
    bool removeItem(std::string itemKey);

    // метод, що шукає Item, за ключем
    // повертає вказівник на перше співпадіння
    // повертає nullptr, якщо не існує
    Item *getItem(std::string itemKey);

    //повертає значення value
    int getValue() const;

    // метод, що друкує вміст LinkedList
    void printList();

    // метод, що повертає кількість елементів у лісті
    int getLength();

    // деструктор
    ~LinkedList();
};
