#ifdef PRIORITY_QUEUE_H

template<class T>
PriorityQueue<T>::PriorityQueue() {
    make_heap(vec.begin(), vec.end());
}

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &pq) {
    vec.erase(vec.begin(), vec.end());

    for(int i = 0; i < pq.getLength(); i++){
        vec.push_back(pq.pos(i));
    }
}

/* Return the current length (number of items) in the queue */
template<class T>
int PriorityQueue<T>::getLength() const {
    return vec.size();
}

/* Returns true if the queue is empty. */
template<class T>
bool PriorityQueue<T>::isEmpty() const {
    return vec.empty();
}

/* Print out the PriorityQueue */
template<class T>
void PriorityQueue<T>::print() const {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << "\n";
}

/* Pushes the val to the top of the queue. */
template<class T>
bool PriorityQueue<T>::push(const T &val) {
    vec.push_back(val);
    push_heap(vec.begin(), vec.end());
    return true;
}

/* Removes and returns the top element from the queue. */
template<class T>
T PriorityQueue<T>::pop() {
    T temp = vec.front();
    pop_heap(vec.begin(), vec.end());
    vec.pop_back();
    return temp;
}

template <class T>
int PriorityQueue<T>::pos(int i) const{
    return vec.at(i);
}

/* Returns if the two lists contain the same elements in the
    * same order.
    */
template<class T>
bool PriorityQueue<T>::operator==(const PriorityQueue<T> &pq) const {
    if(vec.empty() && pq.isEmpty()){
        return true;
    }
    else if(!vec.empty() && pq.isEmpty()){
        return false;
    }
    else if(vec.empty() && !pq.isEmpty()){
        return false;
    }
    else{
        for(int i = 0; i < pq.getLength() && i < vec.size(); i++){
            if(vec.at(i) != pq.pos(i)){
                return false;
            }
            else if(!vec.empty() && pq.isEmpty()){
                return false;
            }
            else if(vec.empty() && !pq.isEmpty()){
                return false;
            }
        }
        return true;
    }
}

template<class T>
PriorityQueue<T>::~PriorityQueue() {
    std::vector<T>().swap(vec);
}

#endif
