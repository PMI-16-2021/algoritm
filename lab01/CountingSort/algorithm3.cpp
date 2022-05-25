#include <iostream>
#include "algorithm3.h"
using namespace std;

void countSort(int array[], int size) {
    // Розмір лічильника має бути принаймні (max+1),але
    // ми не можемо оголосити його як int count(max+1) у C++ тому що
    // він не підтримує динамічне виділення пам'яті.
    // Отже, його розмір надається статично.
    int output[10];
    int count[10];
    int max = array[0];

    // Знайти найбільший елемент масиву
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Ініціалізуємо лічильний масив усіма нулями.
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Зберігає кількість кожного елемента
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Зберігає кумулятивну кількість кожного масиву
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Знайти індекс кожного елемента вихідного масиву в масиві count, і
        // розміщуємо елементи у вихідному масиві
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Копіюємо відсортовані елементи в оригінальний масив
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}