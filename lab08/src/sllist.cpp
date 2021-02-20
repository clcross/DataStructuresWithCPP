#ifdef SLLIST_HPP


template<class T>
SLList<T>::SLList() {
    mHead = NULL;
    mTail = NULL;
}

/* Do a deep copy of sll into the this.
 * Note: This one uses a reference to a Singly Linked List!
 */
template<class T>
SLList<T>::SLList(const SLList<T> &sll) {
    mHead = NULL;
    mTail = NULL;
    SLLNode<T> *copy = sll.mHead;

    for(int i = 0; i < sll.getLength(); i++){
        T temp = copy->mVal;
        append(temp);
        copy = copy->mNext;
    }
}

/* Deconstructor shall free up memory */
template<class T>
SLList<T>::~SLList() {
    while (mHead != NULL && mTail != NULL) {
		   SLLNode<T> *temp = mHead;
		   mHead = mHead->mNext;
		   delete temp;
		   temp = NULL;
	}
	if (mHead == NULL) {
	   mTail = NULL;
	}
}

/* Insert at the end of the list.*/
template<class T>
bool SLList<T>::append(const T &val) {
    SLLNode<T> *rover = new SLLNode<T>;
    rover->set_val(val);
    rover->set_next(NULL);
    if (mHead == NULL){
        mHead = rover;
        mTail = rover;
    }
    else{
        mTail->set_next(rover);
        mTail = mTail->mNext;
    }
    return true;
}

/* Print out the Singly Linked List */
template<class T>
void SLList<T>::print() const {
    SLLNode<T> *rover = mHead;
    while (rover != NULL){
        std::cout << rover->mVal << ", ";
        rover = rover->mNext;
    }
    std::cout << "\n";
}

/* Return the current length of the Singly Linked List */
template<class T>
int SLList<T>::getLength() const {
    SLLNode<T> *rover = mHead;
    int count = 0;
    while (rover != NULL){
        count++;
        rover = rover->mNext;
    }
    return count;
}

/* Insert val at position pos.
 * Return true if successful (it can be placed.)
 * Otherwise return false.
 */
template<class T>
bool SLList<T>::insert(const int pos, const T &val) {
    SLLNode<T> *rover = new SLLNode<T>;
    rover->set_val(val);  
    if (pos == 0){
        rover->set_next(mHead);
        mHead = rover;
    }
    else{
        SLLNode<T> *current = new SLLNode<T>;
        int count = 1;
        current = mHead;
        while (count != pos){
            if (current == NULL){
                return false;
            }
            current = current->mNext;
            count++;
        }
        rover->set_next(current->mNext);
        current->set_next(rover);
    }
    return true;
}

/* Remove the first instance of val
 * Return true if found and removed.
 * Otherwise return false.
 */
template<class T>
bool SLList<T>::remove(const T &val) {
    SLLNode<T> *rover = mHead;
    SLLNode<T> *prev = NULL;
    while (rover != NULL && rover->mVal != val){
        prev = rover;
        rover = rover->mNext;
    }
    if (rover == NULL){
        return false;
    }

    if (mHead == rover){
        mHead = rover->mNext;
        if (rover->mNext == NULL){
            mTail = NULL;
        }
        delete rover;
    }
    else if (rover->mNext == NULL){
        mTail = prev;
        prev->set_next(NULL);
        delete rover;
    }
    else{
        prev->set_next(rover->mNext);
        delete rover;
    }
    return true;
}

/* Retrieves the element at position pos */
template<class T>
T& SLList<T>::operator[](const int pos) {
    SLLNode<T> *rover = mHead;
    int count = 0;
    for (int i = 0; i < pos; i++){
        rover = rover->mNext;
    }
    return rover->mVal;
}

/* Returns if the two lists contain the same elements in the
 * same order.*/
template<class T>
bool SLList<T>::operator==(const SLList<T> &list) const {
    if(mHead == NULL && list.mHead == NULL){
        return true;
    }
    else if(mHead != NULL && list.mHead == NULL){
        return false;
    }
    else if(mHead == NULL && list.mHead != NULL){
        return false;
    }
    else{
        SLLNode<T> *rover = mHead;
        SLLNode<T> *listRover = list.mHead;
        while(rover != NULL){
            if(rover->mVal != listRover->mVal){
                return false;
            }
            else if(rover->mNext != NULL && listRover->mNext == NULL){
                return false;
            }
            else if(rover->mNext == NULL && listRover->mNext != NULL){
                return false;
            }
            else{
                rover = rover->mNext;
                listRover = listRover->mNext;
            }
        }
        return true;
    }
}

/* Empty constructor shall create an empty Linked List! */
template<class T>
DLList<T>::DLList(){
    mHead = NULL;
    mTail = NULL;
}

/* Do a deep copy of dll into the this.
* Note: This one uses a reference to a Singly Linked List!
*/
template<class T>
DLList<T>::DLList(const DLList<T> &dll){
    // mHead = NULL;
    // mTail = NULL;
    // DLLNode<T> *copyHead = dll.mHead;
    // DLLNode<T> *copyTail = dll.mTail;

    // while(copyHead->mNext != copyTail || copyTail->mPrev != copyHead){
    //     T tempHead = copyHead->mVal;
    //     T tempTail = copyTail->mVal;
    //     frontAppend(copyHead);
    //     revAppend(tempTail);
    //     copyHead = copyHead->mNext;
    //     copyTail = copyTail->mPrev;
    // }

    mHead = NULL;
    mTail = NULL;
    DLLNode<T> *copy = dll.mHead;

    for(int i = 0; i < dll.getLength(); i++){
        T temp = copy->mVal;
        append(temp);
        copy = copy->mNext;
    }
}

/* Deconstructor shall free up memory */
template<class T>
DLList<T>::~DLList(){
    while (mHead != NULL && mTail != NULL) {
		   DLLNode<T> *temp = mHead;
		   mHead = mHead->mNext;
		   delete temp;
		   temp = NULL;
	}
	if (mHead == NULL) {
	   mTail = NULL;
	}
}

/* Return the current length of the Singly Linked List */
template<class T>
int DLList<T>::getLength() const{
    DLLNode<T> *rover = mHead;
    int count = 0;
    while (rover != NULL){
        count++;
        rover = rover->mNext;
    }
    return count;
}

/* Insert at the end of the list.*/
template<class T>
bool DLList<T>::append(const T &val){
    DLLNode<T> *rover = new DLLNode<T>;
    rover->set_val(val);
    rover->set_next(NULL);
    rover->set_prev(NULL);
    if (mHead == NULL){
        mHead = rover;
        mTail = rover;
    }
    else{
        mTail->set_next(rover);
        rover->set_prev(mTail);
        mTail = mTail->mNext;
    }
    return true;
}

// /* Insert at the end of the head.*/
// template<class T>
// bool DLList<T>::frontAppend(T &val){
//     DLLNode<T> *rover = new DLLNode<T>;
//     rover->set_val(val);
//     rover->set_next(NULL);
//     rover->set_prev(NULL);
//     if (mHead == NULL){
//         mHead = rover;
//     }
//     else{
//         mHead->set_next(rover);
//         rover->set_prev(mHead);
//         mHead = mHead->mNext;
//     }
//     return true;
// }

// /* Insert at the front of the prev.*/
// template<class T>
// bool DLList<T>::revAppend(const T &val){
//     DLLNode<T> *rover = new DLLNode<T>;
//     rover->set_val(val);
//     rover->set_next(NULL);
//     rover->set_prev(NULL);
//     if (mTail == NULL){
//         mTail = rover;
//     }
//     else{
//         mTail->set_prev(rover);
//         rover->set_next(mTail);
//         mTail = mTail->mPrev;
//     }
//     return true;
// }

/* Insert val at position pos.
* Return true if successful (it can be placed.)
* Otherwise return false.
*/
template<class T>
bool DLList<T>::insert(const int pos, const T &val){
    DLLNode<T> *rover = new DLLNode<T>;
    rover->set_val(val);  
    if (pos == 0){
        rover->set_next(mHead);
        rover->set_prev(NULL);
        mHead = rover;
    }
    else{
        DLLNode<T> *current = new DLLNode<T>;
        int count = 1;
        current = mHead;
        while (count != pos){
            if (current == NULL){
                return false;
            }
            current = current->mNext;
            count++;
        }
        rover->set_next(current->mNext);
        rover->mNext->set_prev(current->mPrev);
        current->set_next(rover);
        rover->set_prev(current);
    }
    return true;
}

/* Print out the Singly Linked List */
template<class T>
void DLList<T>::print() const{
    DLLNode<T> *rover = mHead;
    while (rover != NULL){
        std::cout << rover->mVal << ", ";
        rover = rover->mNext;
    }
    std::cout << "\n";
}

/* Remove the first instance of val
* Return true if found and removed.
* Otherwise return false.
*/
template<class T>
bool DLList<T>::remove(const T &val){
    DLLNode<T> *rover = mHead;
    DLLNode<T> *prev = NULL;
    while (rover != NULL && rover->mVal != val){
        prev = rover;
        rover = rover->mNext;
    }
    if (rover == NULL){
        return false;
    }

    if (mHead == rover){
        mHead = rover->mNext;
        if (rover->mNext == NULL){
            mTail = NULL;
        }
        delete rover;
    }
    else if (rover->mNext == NULL){
        mTail = prev;
        prev->set_next(NULL);
        delete rover;
    }
    else{
        prev->set_next(rover->mNext);
        prev->mNext->set_prev(rover->mPrev);
        delete rover;
    }
    return true;
}

/* Retrieves the element at position pos */
template<class T>
T& DLList<T>::operator[](const int pos){
    DLLNode<T> *rover = mHead;
    int count = 0;
    for (int i = 0; i < pos; i++){
        rover = rover->mNext;
    }
    return rover->mVal;
}

/* Returns if the two lists contain the same elements in the
* same order.
*/
template<class T>
bool DLList<T>::operator==(const DLList<T> &list) const{
    if(mHead == NULL && list.mHead == NULL){
        return true;
    }
    else if(mHead != NULL && list.mHead == NULL){
        return false;
    }
    else if(mHead == NULL && list.mHead != NULL){
        return false;
    }
    else{
        DLLNode<T> *rover = mHead;
        DLLNode<T> *listRover = list.mHead;
        while(rover != NULL){
            if(rover->mVal != listRover->mVal){
                return false;
            }
            else if(rover->mNext != NULL && listRover->mNext == NULL){
                return false;
            }
            else if(rover->mNext == NULL && listRover->mNext != NULL){
                return false;
            }
            else{
                rover = rover->mNext;
                listRover = listRover->mNext;
            }
        }
        return true;
    }
}


#endif
