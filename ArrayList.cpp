#include "ArrayList.h"

template<class T>
void ArrayList<T>::resize() {
    T* temp = new T[arrsize + arrsize / 2];
    for (int i = 0; i < arrsize; i++)
        temp[i] = data[i];
    data = temp;
    arrsize = arrsize + arrsize / 2;
}

template<class T>
bool ArrayList<T>::needtoresize() {
    return arrsize == elements;
}

template<class T>
bool ArrayList<T>::contains(T e) {
    for (int i = 0; i < elements; i++)
        if (data[i] == e)
            return true;
    return false;
}

template<class T>
int ArrayList<T>::indexof(T e) {
    for (int i = 0; i < elements; i++)
        if (data[i] == e)
            return i;
    return -1;
}

template<class T>
int ArrayList<T>::lastindexof(T e) {
    int indexOf = -1;
    for (int i = 0; i < elements; i++)
        if (data[i] == e)
            indexOf = i;
    return indexOf;
}

template<class T>
int ArrayList<T>::size() {
    return size;
}

template<class T>
T ArrayList<T>::get(int index) {
    return data[index];
}

template<class T>
void ArrayList<T>::set(int index, T e) {
    data[index] = e;
}

template<class T>
void ArrayList<T>::add(T e) {
    if (needtoresize())
        resize();
    data[elements] = e;
    elements++;
}

template<class T>
void ArrayList<T>::add(int index, T e) {
    if (needtoresize())
        resize();
    for (int i = elements; i >= index; i--)
        data[i+1] = data[i];
    data[index] = e;
    elements++;
}

