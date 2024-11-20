#pragma once

template <typename T>
class Nodo
{
private:
    T data;
    Nodo* next;
    Nodo* previous;

public:
    Nodo(T value);
    Nodo();

    T getDato();
    Nodo* getNext();
    Nodo* getPrevious();
    void setNext(Nodo<T>* pNext);
    void setPrevious(Nodo<T>* pPrevious);
};


