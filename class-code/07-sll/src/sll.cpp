#include "sll.hpp"
#include <stdlib.h>
#include <iostream>

SLL::SLL() {
    mHead = NULL;
    mTail = NULL;
}

void SLL::push_back(const int val) {
    SLLNode *node = new SLLNode(val, NULL);
    mTail -> set_next(node);
    mTail = node;
}

void SLL::push_front(const int val) {
    SLLNode *node = new SLLNode(val, mHead);
    //node->set_next(mHead);
    mHead = node;
    if (mTail == NULL) {
        mTail = node;
    }
}

void SLL::print() {
    SLLNode *rover = mHead;
    while (rover != NULL) {
        std::cout << rover->get_val() << ", ";
        rover = rover->get_next();
    }
    std::cout << "\n";
}

bool SLL::contains(const int val) {
    SLLNode *rover = mHead;

    while (rover != NULL) {
        if (rover->get_val() == val) {
            return true;
        }
        rover = rover->get_next();
    }

    return false;
}

SLL::~SLL() {
    while (mHead != NULL) {
        remove(mHead->get_val());
    }
}

bool SLL::remove (const int val) {
    SLLNode *rover = mHead;
    SLLNode *prev = NULL;

    while (rover != NULL && rover->get_val() != val) {
        prev = rover;
        rover = rover->get_next();
    }

    // If we did not find, return false!
    if (rover == NULL) { return false; }

    // rover equals the node we need to delete.
    // First case: rover is pointing to the first element
    if (mHead == rover) {
        mHead = rover->get_next();
        // If the Linked List has only one element.
        if (rover->get_next() == NULL) {
            mTail = NULL;
        }
        delete rover;
    } else if (rover->get_next() == NULL) {
        // We are removing the final element, that is NOT head.
        mTail = prev;
        prev->set_next(NULL);
        delete rover;
    } else {
        prev->set_next(rover->get_next());
        delete rover;
    }

    return true;
}
