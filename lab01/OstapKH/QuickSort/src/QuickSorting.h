//
// Created by Ostap Kilbasovych on 11.03.2022.
//

#pragma once

#include <string>

//реалізація, при якій поплавком виступає перший елемент
void swap(int *Ap, int *Bp);
int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);
void printArray(int arr[], int size);
std::string arrayToString(int arr[], int size);




