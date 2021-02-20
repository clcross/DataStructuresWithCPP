#include <stdlib.h>
#include <iostream>
#include "queue.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
    Queue<int> stack;
    stack.push(15);
    stack.push(25);
    stack.push(1);
    std::cout << "top: " << stack.first() << "\n";
    stack.print();
    Queue<int> newStack = Queue<int>(stack);
    newStack.print();
    if(stack == newStack){
        std::cout << "match" << "\n";
    }
    else{
        std::cout << "notmatch" << "\n";
    }
    if(newStack == stack){
        std::cout << "match" << "\n";
    }
    else{
        std::cout << "notmatch" << "\n";
    }
    newStack.pop();
    stack.pop();
    stack.push(100);
    newStack.push(32);
    newStack.push(52);
    newStack.print();
    if(stack == newStack){
        std::cout << "match" << "\n";
    }
    else{
        std::cout << "notmatch" << "\n";
    }
    if(newStack == stack){
        std::cout << "match" << "\n";
    }
    else{
        std::cout << "notmatch" << "\n";
    }
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.pop();
    stack.print();
    newStack.print();
}

