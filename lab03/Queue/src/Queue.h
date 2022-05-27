//
// Created by Ostap Kilbasovych on 11.04.2022.
//
#pragma once

#include <iostream>

template<typename T>
class QueueWithPriority {
private:
    T *dynamicArrayOfT; // динамічний масив елементів типу T
    int *arrayOfPriorities; // масив пріоритетів
    int count; // кількість елементів у черзі
public:
    // конструктор без параметрів
    QueueWithPriority() {
        count = 0;
    }
    // конструктор копіювання
    QueueWithPriority(const QueueWithPriority &otherQueue) {
        // виділяємо памʼять
        dynamicArrayOfT = new T[otherQueue.count];
        arrayOfPriorities = new int[otherQueue.count];
        count = otherQueue.count;

        // поелементне копіювання даних
        for (int i = 0; i < count; i++) {
            dynamicArrayOfT[i] = otherQueue.dynamicArrayOfT[i];
        }

        for (int i = 0; i < count; i++) {
            arrayOfPriorities[i] = otherQueue.arrayOfPriorities[i];
        }
    }
    // деструктор
    ~QueueWithPriority() {
        if (count > 0) {
            delete[] dynamicArrayOfT;
            delete[] arrayOfPriorities;
        }
    }
    // функція, яка додає в чергу новий елемент з пріоритетом
    void Push(T item, int priority);
    // функція, що видаляє з черги елемент з найбільшим пріоритетом
    T Pop();
    // функція, що очищає чергу
    void Clear() {
        if (count > 0) {
            delete[] dynamicArrayOfT;
            delete[] arrayOfPriorities;
            count = 0;
        }
    }
    // функція, що виводить чергу в консоль
    void Print();
    //функція, що повертає елемент з найбільшим пріоритетом
    T Top();
    //функція, що повертає кількість елементів
    int Count();
};

// додає в чергу новий елемент item з пріоритетом
template<typename T>
void QueueWithPriority<T>::Push(T item, int priority) {
    //Створюємо новий масив-чергу та масив-пріоритетів
    T *temporaryDynamicArrayOfT;
    int *temporaryArrayOfPriorities;
    //Виділяємо пам'ять для нових масивів
    temporaryDynamicArrayOfT = new T[count + 1];
    temporaryArrayOfPriorities = new int[count + 1];
    //Пошук позиції position в масиві arrayOfPriorities згідно з пріоритетом, який було передано
    int position;
    if (count == 0) {
        position = 0;
    } else {
        position = 0;
        while (position < count) {
            if (arrayOfPriorities[position] < priority) {
                break;
            }
            ++position;
        }
    }
    //Копіювання даних
    //Індекси масиву з номерами 0..position
    for (int i = 0; i < position; i++) {
        temporaryDynamicArrayOfT[i] = dynamicArrayOfT[i];
        temporaryArrayOfPriorities[i] = arrayOfPriorities[i];
    }
    // Додати елемент в позиції position
    temporaryDynamicArrayOfT[position] = item;
    temporaryArrayOfPriorities[position] = priority;
    // Елементи після позиції position
    for (int i = position + 1; i < count + 1; i++) {
        temporaryDynamicArrayOfT[i] = dynamicArrayOfT[i - 1];
        temporaryArrayOfPriorities[i] = arrayOfPriorities[i - 1];
    }
    // Звільнити пам'ять, попередньо виділену для dynamicArrayOfT та arrayOfPriorities
    if (count > 0) {
        delete[] dynamicArrayOfT;
        delete[] arrayOfPriorities;
    }
    // Перенаправити вказівники зі старого масиву на новий
    dynamicArrayOfT = temporaryDynamicArrayOfT;
    arrayOfPriorities = temporaryArrayOfPriorities;
    // Збільшити кількість елементів у черзі на одиницю
    ++count;
}

// Функція, що видаляє з черги елемент з найбільшим пріоритетом
template<typename T>
T QueueWithPriority<T>::Pop() {
    // Якщо такого елементу не існує, повідомляємо про це і повертаємо NULL
    if (count == 0) {
        std::cout << "There is no such element";
        return 0;
    }
    // Оголошуємо тимчасові масиви
    T *temporaryDynamicArrayOfT;
    int *temporaryArrayOfPriorities;
    //Виділяємо пам'ять для нових масивів
    temporaryDynamicArrayOfT = new T[count - 1]; // на 1 елемент менше
    temporaryArrayOfPriorities = new int[count - 1];
    //Копіюємо елементи без першого
    for (int i = 0; i < count - 1; i++) {
        temporaryDynamicArrayOfT[i] = dynamicArrayOfT[i + 1];
        temporaryArrayOfPriorities[i] = arrayOfPriorities[i + 1];
    }
    //Звільнюємо попередньо виділену пам'ять для dynamicArrayOfT, arrayOfPriorities
    if (count > 0) {
        delete[] dynamicArrayOfT;
        delete[] arrayOfPriorities;
    }
    //Зменшуємо кількість елементів на одиницю
    --count;
    // Перенаправити вказівники зі старого масиву на новий
    dynamicArrayOfT = temporaryDynamicArrayOfT;
    arrayOfPriorities = temporaryArrayOfPriorities;
}

// Функція, що виводить чергу на екран
template<typename T>
void QueueWithPriority<T>::Print() {
    std::cout << "Queue: " << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << "Item: " << dynamicArrayOfT[i] << " - " << "Priority: " << arrayOfPriorities[i] << "\t"
                  << std::endl;
    }
    std::cout << "##############################################" << std::endl;
}

template<typename T>
int QueueWithPriority<T>::Count() {
    return count;
}

template<typename T>
T QueueWithPriority<T>::Top() {
    if (count == 0) {
        return 0;
    } else {
        return dynamicArrayOfT[0];
    }
}