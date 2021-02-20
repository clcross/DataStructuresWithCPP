#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>

template<class T>
class Heap {
    private:
        /* Lets fill out in class. */
        std::vector<T> mHeap;
        int *mSorted;
        int mHeapSize;
    public:

        /* Creates an empty heap. */
        Heap(const int len);

        /* Does a deep copy of the array into the heap. */
        Heap(const T *array, const int size);

        /* Add a given value to the heap.
         * Must maintain ordering!
         */
        void insert(const T &val);

        /* Returns the height of the heap. */
        int getHeight();

        /* Returns the size of the heap. */
        int getSize();

        /* Returns the index if an item if exists in the heap.
         * Otherwise return -1.
         */
        int contains(const T &val) const;

        /* Retrieves the element at position pos */
        T& operator[](const int pos);

        /* Removes and returns the first element */
        T& removeFirst();

        void swap(T& a, T& b) {
            int temp = a;
            a = b;
            b = temp;
        };

        void sift(int index) {
            T largest = index;
            T left = index * 2 + 1;
            T right = index * 2 + 2;

            // std::cout << mHeap[left] << ", " << mHeap[right] << "\n";

            if (right >= mHeapSize) {
                if (left >= mHeapSize) {
                    return;
                }
                else {
                    largest = left;
                }
            }
            else if (mHeap[left] >= mHeap[right]) {
                largest = left;
            }
            else {
                largest = right;
            }

            if (mHeap[index] < mHeap[largest]) {
                swap(mHeap[index], mHeap[largest]);

                sift(largest);
            }
        };

        void print();

        /* Performs a Heap Sort and returns an array of the sorted
         * elements.
         * Note: the heap is empy after the sort!
         */
        // Heap Sort the vector.
        // Create an array of the correct size (on the HEAP the memory!)
        // Set the elements
        // return the new array!
        // Set your heapsize = 0
        // HINT: instead of above think about how your can use remove.
        T* heapSort();

        ~Heap();
};

/* Since heap templated, we include the .cpp.
 * Templated classes are not implemented until utilized (or explicitly
 * declared.)
 */

#include "heap.cpp"

#endif
