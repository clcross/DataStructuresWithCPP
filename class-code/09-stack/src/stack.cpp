#include "stack.hpp"
#include <iostream>

void Stack::push(int val) {
    stack.push_back(val);
}

void Stack::pop() {
    stack.pop_back();
}

int Stack::peek() {
    return stack.back();
}

int Stack::size() {
    return stack.size();
}

void Stack::print() {
    //for (std::list<int>::iterator i = stack.begin(); i != stack.end(); i++) {
    for (auto i = stack.begin(); i != stack.end(); i++) {
        std::cout << *i << ", ";
    }
    std::cout << "\n";
}
