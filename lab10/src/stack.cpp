#ifdef STACK_H
#include <stdlib.h>
#include <iostream>
#include "stack.hpp"

/* Empty constructor shall create an empty Stack! */
template <class T>
Stack<T>::Stack() {
    std::vector<T> stack2;
}

/* Do a deep copy of stack into the this.
* Note: This one uses a reference to a Stack!
*/
template <class T>
Stack<T>::Stack(const Stack<T> &sll) {
    stack2.erase(stack2.begin(), stack2.end());

    for(int i = 0; i < sll.getLength(); i++){
        stack2.push_back(sll.pos(i));
    }
}

/* Deconstructor shall free up memory */
template <class T>
Stack<T>::~Stack() {
    stack2.erase(stack2.begin(), stack2.end());
}

template <class T>
int Stack<T>::pos(int i) const{
    return stack2.at(i);
}

/* Return the current length (number of items) in the stack */
template <class T>
int Stack<T>::getLength() const {
    return stack2.size();
}

/* Pushes the val to the top of the stack. */
template <class T>
bool Stack<T>::push(const T &val) {
    stack2.insert(stack2.begin(), val);
    // stack2.push_back(val);
    return true;
}

/* Returns the top element from the stack. */
template <class T>
T& Stack<T>::top() {
    return stack2.front();
}

/* Removes the top element from the stack. */
template <class T>
void Stack<T>::pop() {
    if (!stack2.empty()){
        stack2.erase(stack2.begin());
    }
}

/* Print out the Stack */
template <class T>
void Stack<T>::print() const {
    for(int i = 0; i < stack2.size(); i++){
        std::cout << stack2.at(i) << ", ";
    }
    std::cout << "\n";
}

/* Returns true if the stack is empty. */
template <class T>
bool Stack<T>::isEmpty() const {
    return stack2.empty();
}

/* Returns if the two stacks contain the same elements in the
* same order.
*/
template <class T>
bool Stack<T>::operator==(const Stack<T> &stack) const{
    if(stack2.empty() && stack.isEmpty()){
        return true;
    }
    else if(!stack2.empty() && stack.isEmpty()){
        return false;
    }
    else if(stack2.empty() && !stack.isEmpty()){
        return false;
    }
    else{
        for(int i = 0; i < stack.getLength() && i < stack2.size(); i++){
            if(stack2.at(i) != stack.pos(i)){
                return false;
            }
            else if(!stack2.empty() && stack.isEmpty()){
                return false;
            }
            else if(stack2.empty() && !stack.isEmpty()){
                return false;
            }
        }
        return true;
    }
}

#endif
