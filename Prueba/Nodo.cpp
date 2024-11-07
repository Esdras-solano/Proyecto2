#include "Nodo.h"

template <typename T>
Nodo<T>::Nodo(T value) : data(value), next(nullptr), previous(nullptr) {}

template <typename T>
Nodo<T>::Nodo() : next(nullptr), previous(nullptr) {}

template <typename T>
T Nodo<T>::getDato() {
    return data;
}

template <typename T>
Nodo<T>* Nodo<T>::getNext() {
    return next;
}

template <typename T>
Nodo<T>* Nodo<T>::getPrevious() {
    return previous;
}

template <typename T>
void Nodo<T>::setNext(Nodo<T>* pNext) {
    this->next = pNext;
}

template <typename T>
void Nodo<T>::setPrevious(Nodo<T>* pPrevious) {
    this->previous = pPrevious;
}


