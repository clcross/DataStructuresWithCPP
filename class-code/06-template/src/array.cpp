#include "array.hpp"

template <class T>
Array<T>::Array(const int size) {
    mSize = size;
    mArray = new T[mSize];
}

template <class T>
T Array<T>::get(int index) {
    return mArray[index];
}

template <class T>
void Array<T>::set(int index, T val) {
    mArray[index] = val;
}
