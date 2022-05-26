//
// Created by Ostap Kilbasovych on 30.03.2022.
//

#include "SetOfStacks.h"

void SetOfStacks::push(double value) {
    if (pointerToTopStack != nullptr && pointerToTopStack->size() < limitOfStackNodes) {
        pointerToTopStack->push(value);
    } else if (pointerToTopStack != nullptr && pointerToTopStack->nextStack != nullptr &&
               pointerToTopStack->nextStack->size() < limitOfStackNodes) {
        pointerToTopStack->nextStack->push(value);
    } else {
        Stack *newStack = new Stack(value);
        newStack->nextStack = pointerToTopStack;
        pointerToTopStack = newStack;
    }
}

int SetOfStacks::size() const {
    int counter = 0;
    Stack *temp;
    if (pointerToTopStack == nullptr) {
        return 0;
    } else {
        temp = pointerToTopStack;
        while (temp != nullptr) {
            ++counter;
            temp = temp->nextStack;
        }
    }
    return counter;
}

void SetOfStacks::print() const {
    Stack *temp = pointerToTopStack;
    int amountOfStacks = size();
    if (temp == nullptr) {
        std::cout << "\nSet of stacks Underflow\n";
        return;
    } else {
        for (int i = 0; i < amountOfStacks; ++i) {
            std::cout << "Stack #" << i + 1 << "\n";
            temp->print();
            temp = temp->nextStack;
        }
    }
}

void SetOfStacks::pop() {
    Stack *temp = pointerToTopStack;
    if (temp == nullptr) {
        std::cout << "\nStack Underflow\n";
        return;
    } else if (pointerToTopStack->isEmpty()) {
        pointerToTopStack = pointerToTopStack->nextStack;
    } else {
        pointerToTopStack->pop();
    }
}

void SetOfStacks::popAt(int numberOfStack) {
    if (numberOfStack <= 0 || numberOfStack > size()) {
        std::cout << "\nYou have tried to access stack which does not exist\n";
    } else {
        Stack *temp = pointerToTopStack;
        for (int i = 0; i < numberOfStack - 1; ++i) {
            temp = temp->nextStack;
        }
        temp->pop();
    }
}
