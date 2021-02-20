#ifndef ARRAY_HPP
#define ARRAY_HPP

template<class T>
class Array {
    public:
        Array(const int size);
        T get(int index);
        void set(int index, T values);
    private:
        T *mArray;
        int mSize;
};

// For templates we include the .cpp
#include "array.cpp"

#endif
