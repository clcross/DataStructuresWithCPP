#ifndef ARRAY_H
#define ARRAY_H

template <class T>
class Array {
    private:
        int mSize;
        int *mArray;

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
    int search(const T &value);

    /* Removes an item at position index by shifting later elements left.
     * Returns true iff 0 <= index < size.
     */
    bool remove(const int index);

    /* Retrieves the element at position pos */
    T& operator[](const int pos) const;

    /* Returns if the two lists contain the same elements in the
     * same order.
     */
    bool operator==(Array<T> &list) const;

    /* Runs a bubble sort algorithm on the array.
     * The array shall be ordered from least to greatest
     */
    void bubbleSort();

    /* Searches for an element with value value and returns the index of that
     * data.
     * NOTE: We assume the array is sorted!
     * Return -1 if the value is not found.
     */
    int binarySearch(const T &value);

    int bSearch(const int *ary, const int size, const T &value);

    /* Free any memory used! */
    ~Array();
};

/* Since Array is templated, we include the .cpp.
 * Templated classes are not implemented until utilized (or explicitly declared).
 */
#include "array.cpp"

#endif
