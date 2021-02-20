#include "binary-search-tree.hpp"
#include <stdlib.h>
#include <iostream>

BSTNode::BSTNode() {
    mVal = -1;
    mLeft = mRight = NULL;
}
BSTNode::BSTNode(const int val, BSTNode *left, BSTNode *right) {
    set_val(val);
    set_left(left);
    set_right(right);
}
BSTNode* BSTNode::get_right() {
    return mRight;
}
BSTNode* BSTNode::get_left() {
    return mLeft;
}
void BSTNode::set_left(BSTNode *node) {
    mLeft = node;
}
void BSTNode::set_right(BSTNode *node) {
    mRight = node;
}
int BSTNode::get_val() {
    return mVal;
}
void BSTNode::set_val(const int val) {
    mVal = val;
}

BST::BST() {
    mRoot = NULL;
}

void add_rec(BSTNode *rover, BSTNode *to_add) {
    if (rover == NULL || to_add == NULL) { return; }

    if (rover->get_val() < to_add->get_val()) {
        if (rover->get_right() == NULL) {
            rover->set_right(to_add);
            return;
        }
        add_rec(rover->get_right(), to_add);
    }
    else if (rover->get_val() > to_add->get_val()) {
        if (rover->get_left() == NULL) {
            rover->set_left(to_add);
            return;
        }
        add_rec(rover->get_left(), to_add);
    } 
}

void BST::add(int val) {
    BSTNode *to_add = new BSTNode(val, NULL, NULL);
    BSTNode *rover = mRoot;

    // This is a guard.
    if (rover == NULL){
        mRoot = to_add;
        return;
    }

    add_rec(mRoot, to_add);
    /*
    while (rover != NULL) {
        if (rover->get_val() < to_add->get_val()) {
            if (rover->get_right() == NULL) {
                rover->set_right(to_add);
                return;
            }
            rover = rover->get_right();
        } 
        else if (rover->get_val() > to_add->get_val()) {
            if (rover->get_left() == NULL) {
                rover->set_left(to_add);
                return;
            }
            rover = rover->get_left();
        } 
        else {
            // It is equal, we do not allow duplicates!
            return;
        }
    }
    */
}

bool BST::remove(int val) {
    return false;
}

bool BST::contains(int val) {
    return false;
}

void print_bst(BSTNode *node) {
    // Base case
    if (!node) { return; }

    print_bst(node->get_left());
    std::cout << node->get_val() << " ";
    print_bst(node->get_right());
}

void BST::print() {
    print_bst(mRoot);
    std::cout << "\n";
}

