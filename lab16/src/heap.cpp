#ifdef HEAP_H

template<class T>
Heap<T>::Heap(const int len) {
    mHeap.resize(len);
    mHeapSize = 0;
}

/* Does a deep copy of the array into the heap. */
template<class T>
Heap<T>::Heap(const T *array, const int size) {
    mHeapSize = size;
    mHeap = new std::vector<T>;
    for (int i = 0; i < mHeapSize; i++){
        mHeap[i] = array[i];
    }
}

template<class T>
void Heap<T>::insert(const T& element) {
    // We do need to check if the heap has enough space.
    // Add the element to the end to maintain balance and left-justification.
    int cindex = mHeapSize;
    mHeap[mHeapSize] = element;
    mHeapSize++;
    // sift up!
    int parent_index = (cindex - 1) /2;
    while (mHeap[cindex] > mHeap[parent_index]) {
        T temp = mHeap[cindex];
        mHeap[cindex] = mHeap[parent_index];
        mHeap[parent_index] = temp;

        // iterator on.
        cindex = parent_index;
        parent_index = (cindex - 1) /2;
    }
}

/* Returns the height of the heap. */
template<class T>
int Heap<T>::getHeight() {
    return (mHeapSize / 2);
}

template<class T>
T& Heap<T>::operator[](const int pos) {
    return mHeap[pos];
}

/* Returns the size of the heap. */
template<class T>
int Heap<T>::getSize() {
    return mHeapSize;
}

/* Returns the index if an item if exists in the heap.
* Otherwise return -1.
*/
template<class T>
int Heap<T>::contains(const T &val) const {
    int location = 0;
    bool hasNum = false;
    for (int i = 0; i < mHeap.size(); i++) { 
        if (mHeap.at(i) == val) {
            location = i;
            hasNum = true;
        }
    }
    if(hasNum == true) {
        return location;
    }
    else{
        return -1;
    }
}

/* Removes and returns the first element */
template<class T>
T& Heap<T>::removeFirst() {
    swap(mHeap[0], mHeap[mHeapSize - 1]);
    
    mHeapSize--;

    sift(0);
    
    // std::cout << "removing: " << mHeap[mHeapSize] << ", ";
    return mHeap[mHeapSize];
}

template<class T>
T* Heap<T>::heapSort() {
    mSorted = new int[mHeapSize];
    // int tempSize = mHeapSize;
    while (mHeapSize > 0) {
        mSorted[mHeapSize] = removeFirst();
        // std::cout << (mHeapSize) << ": " << mSorted[mHeapSize] << ", ";
    }
    // std::cout << "\n";

    // for (int i = 0; i < tempSize; i++) {
    //     std::cout << mSorted[i] << ", ";
    // }
    // std::cout << "\n";
    return mSorted;
}

template<class T>
Heap<T>::~Heap() {
    std::vector<T>().swap(mHeap);
    delete[] mSorted;
}

template<class T>
void Heap<T>::print() {
    for (int i = 0; i < mHeapSize; i++) {
        std::cout << mHeap[i] << ", ";
    }
    std::cout << "\n";
}

#endif
