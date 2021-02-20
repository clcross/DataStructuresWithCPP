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
    mSize = sll.getLength();
    SLLNode *copy = sll.mHead;

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
		   SLLNode *temp = mHead;
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
    SLLNode *rover = new SLLNode;
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

template<class T>
void SLList<T>::fill(){
    int num;
    srand(time(NULL));
    for(int i = 0; i < 10000; i++){
        num = rand() % 10000 + 1;
        this->append(num);
    }
}

/* Print out the Singly Linked List */
template<class T>
void SLList<T>::print() const {
    SLLNode *rover = mHead;
    while (rover != NULL){
        std::cout << rover->mVal << ", ";
        rover = rover->mNext;
    }
    std::cout << "\n";
}

/* Return the current length of the Singly Linked List */
template<class T>
int SLList<T>::getLength() const {
    SLLNode *rover = mHead;
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
    SLLNode *rover = new SLLNode;
    rover->set_val(val);  
    if (pos == 0){
        rover->set_next(mHead);
        mHead = rover;
    }
    else{
        SLLNode *current = new SLLNode;
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
    SLLNode *rover = mHead;
    SLLNode *prev = NULL;
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
    SLLNode *rover = mHead;
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
        SLLNode *rover = mHead;
        SLLNode *listRover = list.mHead;
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

template<class T>
void SLList<T>::merge(SLLNode **start1, SLLNode **end1, SLLNode **start2, SLLNode **end2) { 
  
    // Making sure that first node of second 
    // list is higher. 
    struct SLLNode *temp = NULL; 
    if ((*start1)->mVal > (*start2)->mVal) { 
        // SLLNode *startTemp;
        // SLLNode *endTemp;

        std::swap(*start1, *start2); 
        std::swap(*end1, *end2); 
    } 
  
    // Merging remaining nodes 
    struct SLLNode *astart = *start1, *aend = *end1; 
    struct SLLNode *bstart = *start2, *bend = *end2; 
    struct SLLNode *bendnext = (*end2)->mNext; 
    while (astart != aend && bstart != bendnext) { 
        if (astart->mNext->mVal > bstart->mVal) { 
            temp = bstart->mNext; 
            bstart->mNext = astart->mNext; 
            astart->mNext = bstart; 
            bstart = temp; 
        } 
        astart = astart->mNext; 
    } 
    if (astart == aend) 
        astart->mNext = bstart; 
    else
        *end2 = *end1; 
} 

template<class T>
void SLList<T>::sort(){
    if (mHead == NULL){return;}

    clock_t timestart, diff;
    double timeAmount;
    std::ofstream SLLMerge;
    SLLMerge.open ("dataFiles/SLLMerge.txt");
    int timekeeper = 0;

    struct SLLNode *start1 = NULL, *end1 = NULL; 
    struct SLLNode *start2 = NULL, *end2 = NULL; 
    struct SLLNode *prevend = NULL; 
    int len = this->getLength(); 
  
    for (int gap = 1; gap < len; gap = gap*2) { 
        timestart = clock();
        start1 = mHead;
        while (start1) { 
            bool isFirstIter = 0; 
            if (start1 == mHead) {
                isFirstIter = 1; 
            }
            int counter = gap; 
            end1 = start1; 
            while (--counter && end1->mNext) {
                end1 = end1->mNext; 
            }
            start2 = end1->mNext; 
            if (!start2) {
                break;
            } 
            counter = gap; 
            end2 = start2; 
            while (--counter && end2->mNext) {
                end2 = end2->mNext;
            }

            SLLNode *temp = end2->mNext;
            merge(&start1, &end1, &start2, &end2); 
  
            if (isFirstIter) {
                mHead = start1;
            }
            else{
                prevend->mNext = start1; 
            }
            prevend = end2; 
            start1 = temp; 
        }
        prevend->mNext = start1;
        diff = clock() - timestart;
        timeAmount = diff * 1.0 / CLOCKS_PER_SEC;
        SLLMerge << timekeeper << " " << timeAmount << "\n";
        SLLMerge << std::flush;
        timekeeper = timekeeper + 1;
    }
    SLLMerge.close();
}

#endif
