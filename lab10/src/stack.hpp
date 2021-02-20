#ifndef STACK_H
#define STACK_H

#include <vector>

template<class T>
class Stack {
    private:
        std::vector<T> stack2;
    public:
        /* Empty constructor shall create an empty Stack! */
        Stack();
        /* Do a deep copy of stack into the this.
         * Note: This one uses a reference to a Stack!
         */
        Stack(const Stack<T> &stack);
        /* Deconstructor shall free up memory */
        ~Stack();
        /* Return the current length (number of items) in the stack */
        int getLength() const;
        /* Returns true if the stack is empty. */
        bool isEmpty() const;
        /* Print out the Stack */
        void print() const;
        /* Pushes the val to the top of the stack. */
        bool push(const T &val);
        /* Returns the top element from the stack. */
        T& top();
        int pos(int i) const;
        /* Removes the top element from the stack. */
        void pop();
        /* Returns if the two stacks contain the same elements in the
         * same order.
         */
        bool operator==(const Stack<T> &stack) const;
};

#include "stack.cpp"

#endif
