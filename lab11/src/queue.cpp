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

template <class T>
void Queue<T>::sort() {
    int mSize = queue2.size();
    for (int i = 0; i < mSize; i++){
        for (int j = 0; j < mSize - 1; j++){
            if (queue2.at(j) < queue2.at(j+1)){
                T temp = queue2.at(j);
                queue2.at(j) = queue2.at(j+1);
                queue2.at(j+1) = temp;
            }
        }
    }
}

template <class T>
int Queue<T>::bSearch(std::vector<T> vec, int begin, int end, const T &val){
    // this->sort();
    if(begin > end){
        return -1;
    }

    const int middle = begin + ((end - begin) / 2);

    if(vec.at(middle) == val){
        return middle;
    }
    else if(vec.at(middle) > val){
        return bSearch(vec, begin, middle - 1, val);
    }
    else{
        return bSearch(vec, middle + 1, end, val);
    }
}

/* Add a value to the queue with respect to priority.
* For this function a lower number is a higher priority.
* EX: If the Queue is of integers and is { 5, 10, 15} and I add 7, 
* the new queue is { 5, 7, 10, 15}.
*/
template <class T>
void Queue<T>::addWithPriority(const T& val){
    if(queue2.size() == 0){
        queue2.push_back(val);
    }
    else{
        int i = 0;
        bool inserted = false;
        while(!inserted){
        if(queue2.at(i) < val){
                queue2.insert(queue2.begin() + i, val);
                inserted = true;
            }
            else if(i == queue2.size() - 1){
                queue2.push_back(val);
                inserted = true;
            }
            else{
                i++;
            }
        }
    }
}

/* Return the length of the shortest path, but with warps.  The map is
* a 2D array with each cell having the following property
*   0: Cell is open (passable)
*  -1: Cell is a wall (unpassable)
* > 0: Cell is a warp.
* A warp is a value > 999 and warps to the position 
* (<first three digits, second three digits).
* Hence 1000 warps to (1, 0), and 203109 warps to (203, 109)
* To get the x value: <cell>/1000
* To get the y value: <cell>%1000
*/
template <class T>
int Queue<T>::getShortestPathWithWarps(int **map, int width, int length, int sx, int sy, int ex, int ey){
    std::vector<Point> to_visit;
    to_visit.push_back(Point(sx, sy, 0));
    int warp = 0;

    while(!to_visit.empty()){
        Point p = to_visit.front();
        to_visit.pop_back();
        std::cout << "(" << p.x << ", " << p.y << ")\n";

        if(map[p.x][p.y] == 2){
            continue;
        }
        if(map[p.x][p.y] < 0){
            continue;
        }
        if(map[p.x][p.y] > 999){
            to_visit.push_back(Point(map[p.x][p.y]/1000, map[p.x][p.y]%1000, p.steps + 1));
        }
        if(p.x == ex && p.y == ey){
            return p.steps;
        }
        map[p.x][p.y] = 2;

        if(p.y + 1 < length){
            to_visit.push_back(Point(p.x, p.y + 1, p.steps + 1));
        }
        if(p.x + 1 < width){
            to_visit.push_back(Point(p.x + 1, p.y, p.steps + 1));
        }
        if(p.y - 1 >= 0){
            to_visit.push_back(Point(p.x, p.y - 1, p.steps + 1));
        }
        if(p.x - 1 >= 0){
            to_visit.push_back(Point(p.x - 1, p.y, p.steps + 1));
        }
    }
    return -1;
}

#endif