#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
class PriorityQueue {
    private:
        std::vector<T> vec;
    public:
        /* Empty constructor shall create an empty PriorityQueue! */
        PriorityQueue();

        /* Do a deep copy of queue into the this.
         * Note: This one uses a reference to a PriorityQueue!
         */
        PriorityQueue(const PriorityQueue<T> &pq);

        /* Deconstructor shall free up memory */
        ~PriorityQueue();

        /* Return the current length (number of items) in the queue */
        int getLength() const;

        /* Returns true if the queue is empty. */
        bool isEmpty() const;

        /* Print out the PriorityQueue */
        void print() const;

        /* Pushes the val to the top of the queue. */
        bool push(const T &val);

        /* Removes and returns the top element from the queue. */
        T pop();

        int pos(int i) const;

        /* Returns if the two lists contain the same elements in the
         * same order.
         */
        bool operator==(const PriorityQueue<T> &pq) const;
};

#include "priorityqueue.cpp"

#endif
