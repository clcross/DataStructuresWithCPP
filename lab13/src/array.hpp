#ifndef ARRAY_H
#define ARRAY_H

#include <time.h>
#include <fstream>
#include <stdlib.h>

template <class T>
class Array {
    private:
        T *mArray;
        int mSize;
        void msort(T *list, const int len);
        T *mMergeArray;

    public:
    /* Do a deep copy of the array into the list.
     * Note: This one uses a pointer!
     */
    Array(const T *array, const int size);
    /* Do a deep copy of the array into the list
     * Note: This one uses a reference to a List!
     */
    Array(const Array<T> &list);

    /* Return the current length of the array */
    int getLength() const;

    /* Returns the index in the array where value is found.  
     * Return -1 if value is not present in the array.
     */
    int indexOf(const T &value);

    /* Removes an item at position index by shifting later elements left.
     * Returns true iff 0 <= index < size.
     */
    bool remove(const int index);

    void print();

    /* Retrieves the element at position pos */
    T& operator[](const int pos) const;

    /* Returns if the two lists contain the same elements in the
     * same order.
     */
    bool operator==(Array<T> &list) const;

    void quick_sort(int *ary, const int size);

    /* Runs a quick sort algorithm on the array.
    * The array shall be ordered from least to greatest */
    void qsort();

    void merge(int arr[], int l, int m, int r);

    /* Runs a merge sort algorithm on the array.
    * The array shall be ordered from least to greatest */
    void msort();

    /* Runs the sort routing you believe is the best. */
    void sort();

    /* Free any memory used! */
    ~Array();
};

/* Since Array is templated, we include the .cpp.
 * Templated classes are not implemented until utilized (or explicitly declared).
 */
#include "array.cpp"

#endif
