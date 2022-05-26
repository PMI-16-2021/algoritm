#include "LinkedList.h"

// Конструктор по замовчуванню
// Створює голову і задає розмір 0
LinkedList::LinkedList() {
    head = new Item;
    head->next = nullptr;
    length = 0;
}

// вставляємо елемент в кінець списку
void LinkedList::insertItem(Item *newItem) {
    if (!head->next) {
        head->next = newItem;
        ++length;
        return;
    }
    Item *p = head;
    Item *q = head;
    while (q) {
        p = q;
        q = p->next;
    }
    p->next = newItem;
    newItem->next = nullptr;
    ++length;
}

// видаляє елемент за ключем
// повертає true якщо операція успішна
bool LinkedList::removeItem(std::string itemKey) {
    if (!head->next) return false;
    Item *p = head;
    Item *q = head;
    while (q) {
        if (q->key == itemKey) {
            p->next = q->next;
            delete q;
            length--;
            return true;
        }
        p = q;
        q = p->next;
    }
    return false;
}

// Шукає елемент за ключем
// Повертає вказівник на перший знайдений елемент
// Повертає nullptr якщо, такого елементу не знайдено
Item *LinkedList::getItem(std::string itemKey) {
    Item *p = head;
    Item *q = head;
    while (q) {
        p = q;
        if ((p != head) && (p->key == itemKey))
            return p;
        q = p->next;
    }
    return nullptr;
}

// Друкуємо вміст ліста
void LinkedList::printList() {
    if (length == 0) {
        std:std::cout << "\n{ }\n";
        return;
    }
    Item *p = head;
    Item *q = head;
    std::cout << "\n{ ";
    while (q) {
        p = q;
        if (p != head) {
            std::cout << "Key: ";
            std::cout << p->key << "; ";
            std::cout << "Value: ";
            std::cout << p->value;
            if (p->next) std::cout << ", ";
            else std::cout << " ";
        }
        q = p->next;
    }
    std::cout << "}\n";
}

// повертаємо розмір ліста
int LinkedList::getLength() {
    return length;
}

// деструктор
LinkedList::~LinkedList() {
    Item *p = head;
    Item *q = head;
    while (q) {
        p = q;
        q = p->next;
        if (q) delete p;
    }
}
//повертаємо value за ключем
int LinkedList::getValue() const {
    return head->value;
}

int Item::getValue() const {
    return this->value;
}
