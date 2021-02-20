#ifndef QUEUE_H
#define QUEUE_H

#include <vector>

template<class T>
class Queue {
    private:
        std::vector<T> queue2;
    public:
        /* Empty constructor shall create an empty Queue! */
        Queue();
        /* Do a deep copy of queue into the this.
         * Note: This one uses a reference to a Queue!
         */
        Queue(const Queue<T> &queue);
        /* Deconstructor shall free up memory */
        ~Queue();
        /* Return the current length (number of items) in the queue */
        int getLength() const;
        /* Returns true if the queue is empty. */
        bool isEmpty() const;
        /* Print out the Queue */
        void print() const;
        /* Pushes the val to the end of the queue. */
        bool push(const T &val);
        /* returns the first element from the queue. */
        T& first();

        int pos(int i) const;
        /* Removes the first element from the queue. */
        void pop();
        /* Returns if the two queues contain the same elements in the
         * same order.
         */
        bool operator==(const Queue<T> &queue) const;
};

#include "queue.cpp"

#endif
