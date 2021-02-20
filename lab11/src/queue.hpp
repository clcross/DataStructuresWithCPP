#ifndef QUEUE_H
#define QUEUE_H
#include <vector>

class Point{
    public:
        int x, y, steps;
        Point(int _x, int _y, int _steps){
            x = _x;
            y = _y;
            steps = _steps;
        }
};

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

        // gets the position of value
        int pos(int i) const;

        /* Pushes the val to the end of the queue. */
        bool push(const T &val);

        /* returns the first element from the queue. */
        T& first();

        /* Removes the first element from the queue. */
        void pop();

        /* Returns if the two queues contain the same elements in the
         * same order.
         */
        bool operator==(const Queue<T> &queue) const;

        void sort();

        int bSearch(std::vector<T> vec, int begin, int end, const T &val);

        /* Add a value to the queue with respect to priority.
        * For this function a lower number is a higher priority.
        * EX: If the Queue is of integers and is { 5, 10, 15} and I add 7, 
        * the new queue is { 5, 7, 10, 15}.
        */
        void addWithPriority(const T& val);

        /* Return the length of the shortest path, but with warps.  The map is
        * a 2D array with each cell having the following property
        *   0: Cell is open (passable)
        *  -1: Cell is a wall (unpassable)
        * > 0: Cell is a warp.
        * A warp is a value > 0 and warps to the position 
        *    (<first three digits, second three digits).
        * Hence 1000 warps to (1, 0), and 203109 warps to (203, 109)
        * To get the x value: <cell>/1000
        * To get the y value: <cell>%1000
        */
        int getShortestPathWithWarps(int **map, int width, int length, int sx, int sy, int ex, int ey);
};

#include "queue.cpp"

#endif
