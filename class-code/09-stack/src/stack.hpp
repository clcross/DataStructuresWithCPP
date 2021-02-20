#ifndef STACK_HPP
#define STACK_HPP

#include <list>

class Stack {
    private:
        std::list<int> stack;
    public:
        void push(int val);
        void pop();
        int peek();
        int size();
        void print();
};

#endif
