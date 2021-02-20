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
    mMergeArray = new T[mSize];
    for (int i = 0; i < mSize; i++){
        mArray[i] = array[i];
        mMergeArray[i] = array[i];
    }
}

/* Do a deep copy of the array into the list
 * Note: This one uses a reference to a List!
 */
template <class T>
Array<T>::Array(const Array<T> &list){
    mSize = list.mSize;
    mArray = new T[mSize];
    mMergeArray = new T[mSize];
    for (int i = 0; i < mSize; i++){
        mArray[i] = list[i];
        mMergeArray[i] = list[i];
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

template <class T>
void Array<T>::quick_sort(int *ary, const int size){
    int pivot = ary[size/2];
    int small_index = 0;
    if (size < 2){return;}
    
    for (int i = 1; i < size; i++){
        if (ary[i] < pivot){
            int temp = ary[small_index + 1];
            ary[small_index + 1] = ary[i];
            ary[i] = temp;
            small_index++;
        }
    }
    ary[0] = ary[small_index];
    ary[small_index] = pivot;

    quick_sort(ary, small_index);
    if(small_index == 0){
        quick_sort(ary + 1, size - 1);
    }
    else{
        quick_sort(ary + small_index, size - small_index);
    }
}


/* Runs a quick sort algorithm on the array.
* The array shall be ordered from least to greatest */
template <class T>
void Array<T>::qsort(){
    quick_sort(mArray, mSize);
}

template <class T>
void Array<T>::merge(int arr[], int left, int middle, int right){ 
    int i, j, k; 
    int n1 = middle - left + 1; 
    int n2 =  right - middle; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++){
        L[i] = arr[left + i]; 
    }

    for (j = 0; j < n2; j++){
        R[j] = arr[middle + 1+ j]; 
    }
  
    i = 0; 
    j = 0; 
    k = left; 
    while (i < n1 && j < n2){ 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1){ 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2){ 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

template <class T>
void Array<T>::msort(T *list, const int len){
    int curr_size; 
    int left_start;
    int i = 0;

    for (curr_size = 1; curr_size <= len-1; curr_size = 2 * curr_size){ 
        for (left_start=0; left_start < len - 1; left_start += 2 * curr_size){ 

            int mid = std::min(left_start + curr_size - 1, len - 1); 

            int right_end = std::min(left_start + 2*curr_size - 1, len - 1); 

            merge(list, left_start, mid, right_end); 
        } 
    } 
}

/* Runs a merge sort algorithm on the array.
* The array shall be ordered from least to greatest */
template <class T>
void Array<T>::msort(){
    if (mSize <= 0){
        return;
    }
    else{
        msort(mMergeArray, mSize);
    }
}

/* Runs the sort routing you believe is the best. */
template <class T>
void Array<T>::sort(){
    this->qsort();
}

template <class T>
Array<T>::~Array() {
    delete[] mArray;
    delete[] mMergeArray;
}

#endif
