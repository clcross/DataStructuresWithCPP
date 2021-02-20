#ifdef QUEUE_H
#include "queue.hpp"
#include <stdlib.h>
#include <iostream>

/* Empty constructor shall create an empty queue! */
template <class T>
Queue<T>::Queue() {
    std::vector<T> queue2;
}

/* Do a deep copy of queue into the this.
* Note: This one uses a reference to a queue!
*/
template <class T>
Queue<T>::Queue(const Queue<T> &queue) {
    queue2.erase(queue2.begin(), queue2.end());

    for(int i = 0; i < queue.getLength(); i++){
        queue2.push_back(queue.pos(i));
    }
}

/* Deconstructor shall free up memory */
template <class T>
Queue<T>::~Queue() {
    queue2.erase(queue2.begin(), queue2.end());
}

template <class T>
int Queue<T>::pos(int i) const{
    return queue2.at(i);
}

/* Return the current length (number of items) in the queue */
template <class T>
int Queue<T>::getLength() const {
    return queue2.size();
}

/* Pushes the val to the top of the queue. */
template <class T>
bool Queue<T>::push(const T &val) {
    queue2.insert(queue2.begin(), val);
    // queue2.push_back(val);
    return true;
}

/* Returns the top element from the queue. */
template <class T>
T& Queue<T>::first() {
    return queue2.back();
}

/* Removes the front element from the queue. */
template <class T>
void Queue<T>::pop() {
    if (!queue2.empty()){
        queue2.pop_back();
    }
}

/* Print out the queue */
template <class T>
void Queue<T>::print() const {
    for(int i = 0; i < queue2.size(); i++){
        std::cout << queue2.at(i) << ", ";
    }
    std::cout << "\n";
}

/* Returns true if the queue is empty. */
template <class T>
bool Queue<T>::isEmpty() const {
    return queue2.empty();
}

/* Returns if the two queues contain the same elements in the
* same order.
*/
template <class T>
bool Queue<T>::operator==(const Queue<T> &queue) const{
    if(queue2.empty() && queue.isEmpty()){
        return true;
    }
    else if(!queue2.empty() && queue.isEmpty()){
        return false;
    }
    else if(queue2.empty() && !queue.isEmpty()){
        return false;
    }
    else{
        for(int i = 0; i < queue.getLength() && i < queue2.size(); i++){
            if(queue2.at(i) != queue.pos(i)){
                return false;
            }
            else if(!queue2.empty() && queue.isEmpty()){
                return false;
            }
            else if(queue2.empty() && !queue.isEmpty()){
                return false;
            }
        }
        return true;
    }
}

#endif