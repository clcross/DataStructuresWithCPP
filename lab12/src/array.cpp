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
int Array<T>::indexOf(const T &value){
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

template <class T>
void Array<T>::print(){
    for (int i = 0; i < mSize; i++){
        std::cout << mArray[i] << ", ";
    }
    std::cout << "\n";
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
    clock_t start, diff;
    double timeAmount;
    std::ofstream bubble;
    bubble.open ("dataFiles/bubble.txt");
    
    for (int i = 0; i < mSize; i++){
        start = clock();
        for (int j = 0; j < mSize - 1; j++){
            if (mArray[j] > mArray[j + 1]){
                int temp = mArray[j];
                mArray[j] = mArray[j + 1];
                mArray[j + 1] = temp;
            }
        }
        diff = clock() - start;
        timeAmount = diff * 1.0 / CLOCKS_PER_SEC;
        bubble << i << " " << timeAmount << "\n";
        bubble << std::flush;
    }
    bubble.close();
}

/* Runs a selection sort algorithm on the array.
* The array shall be ordered from least to greatest
*/
template <class T>
void Array<T>::selectionSort(){
    clock_t start, diff;
    double timeAmount;
    std::ofstream selection;
    selection.open ("dataFiles/selection.txt");

    int minIndex;
    int temp;
    for (int i = 0; i < mSize; i++){
        start = clock();
        minIndex = i;
        for (int j = i; j < mSize; j++){
            if (mArray[j] < mArray[minIndex]){
                minIndex = j;
            }
        }
        temp = mArray[i];
        mArray[i] = mArray[minIndex];
        mArray[minIndex] = temp;
        diff = clock() - start;
        timeAmount = diff * 1.0 / CLOCKS_PER_SEC;
        selection << i << " " << timeAmount << "\n";
        selection << std::flush;
    }
    selection.close();
}

/* Runs a insertion sort algorithm on the array.
* The array shall be ordered from least to greatest
*/
template <class T>
void Array<T>::insertionSort(){
    clock_t start, diff;
    double timeAmount;
    std::ofstream insertion;
    insertion.open ("dataFiles/insertion.txt");

    int temp;
    int j;  
    for (int i = 1; i < mSize; i++){  
        start = clock();
        temp = mArray[i];  
        j = i - 1;  
  
        while (j >= 0 && mArray[j] > temp){  
            mArray[j + 1] = mArray[j];  
            j = j - 1;  
        }  
        mArray[j + 1] = temp;  
        diff = clock() - start;
        timeAmount = diff * 1.0 / CLOCKS_PER_SEC;
        insertion << i << " " << timeAmount << "\n";
        insertion << std::flush;
    } 
    insertion.close();
    
}

/* Runs the sort routing you believe is the best. */
template <class T>
void Array<T>::sort(){
    this->selectionSort();
}

template <class T>
Array<T>::~Array() {
    delete[] mArray;
}

#endif
