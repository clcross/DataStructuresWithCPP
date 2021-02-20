#include "priorityqueue.hpp"

int main(int argc, char *argv[]) {
    PriorityQueue<int> pq;

    pq.push(12);
    pq.push(14);
    pq.push(35);
    pq.push(85);
    pq.push(1);
    pq.push(46);
    pq.push(62);
    pq.push(21);

    pq.print();

    std::cout << "popping: " << pq.pop() << "\n";
    pq.print();
    std::cout << "popping: " << pq.pop() << "\n";

    PriorityQueue<int> newpq = PriorityQueue<int>(pq);

    newpq.push(50);
    newpq.print();

    if (newpq == pq) {
        std::cout << "match\n";
    }
    else {
        std::cout << "notmatch\n";
    }

}
