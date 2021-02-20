/* Array is templated, therefore only include the code if it is included from
 * the header file! 
 */
#ifdef ARRAY_H
#include <stdio.h>

/* Do a deep copy of the array into the list.
 * Note: This one uses a pointer!
 */
template <class T>
Array<T>::Array(const T *array, const int size){
    mSize = size;
    mArray = new T[mSize];
    for (int i = 0; i < mSize; i++){
        mArray[i] = array[i];
    }
}

/* Do a deep copy of the array into the list
 * Note: This one uses a reference to a List!
 */
template <class T>
Array<T>::Array(const Array<T> &list){
    mSize = list.mSize;
    mArray = new T[mSize];
    for (int i = 0; i < mSize; i++){
        mArray[i] = list[i];
    }
}

/* Return the current length of the array */
template <class T>
int Array<T>::getLength() const{
    return mSize;
}

/* Returns the index in the array where value is found.  
* Return -1 if value is not present in the array.
*/
template <class T>
int Array<T>::search(const T &value){
    int location = 0;
    bool hasNum = false;
    for (int i = 0; i < mSize; i++){
        if (mArray[i] == value){
            location = i;
            hasNum = true;
        }
    }
    if (hasNum == true){
        return location;
    }
    else{
        return -1;
    }
}

/* Removes an item at position index by shifting later elements left.
* Returns true iff 0 <= index < size.
*/
template <class T>
bool Array<T>::remove(const int index){
    if (0 <= index && index < mSize){
        mSize--;
        for (int i = index; i < mSize; i++){
            mArray[i] = mArray[i + 1];
        }
        return true;        
    }
    else{
        return false;
    }
}

/* Retrieves the element at position pos */
template <class T>
T& Array<T>::operator[](const int pos) const{
    return mArray[pos];
}

/* Returns true if the two lists contain the same elements in the
* same order.
*/
template <class T>
bool Array<T>::operator==(Array<T> &list) const{
    int listSize = sizeof(list)/sizeof(list[0]);
    bool match = false;
    for (int i = 0; i < listSize; i++){
        if (mArray[i] == list[i]){
            match = true;
        }
        else{
            return false;
        }
    }
    return match;
}

/* Runs a bubble sort algorithm on the array.
* The array shall be ordered from least to greatest
*/
template <class T>
void Array<T>::bubbleSort(){
    for (int i = 0; i < mSize; i++){
        for (int j = 0; j < mSize - 1; j++){
            if (mArray[j] > mArray[j + 1]){
                int temp = mArray[j];
                mArray[j] = mArray[j + 1];
                mArray[j + 1] = temp;
            }
        }
    }
}

/* Searches for an element with value value and returns the index of that
* data.
* NOTE: We assume the array is sorted!
* Return -1 if the value is not found.
*/
template <class T>
int Array<T>::binarySearch(const T &value){
    return bSearch(mArray, mSize, value);
}

template <class T>
int Array<T>::bSearch(const int *ary, const int size, const T &value){
    if (ary == NULL || size < 1){
        return -1;
    }

    int offset = ((size + 1) % 2);
    int mid = (size / 2);

    if (ary[mid] == value){
        return mid;
    }

    if (ary[mid] > value){
        return bSearch(ary, mid, value);
    }
    
    return mid + 1 + bSearch(ary + (mid + 1), mid - offset, value);

}

template <class T>
Array<T>::~Array() {
    delete[] mArray;
}

#endif
