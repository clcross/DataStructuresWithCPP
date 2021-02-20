// website used to get avl implementation https://www.tutorialspoint.com/cplusplus-program-to-implement-avl-tree
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <string>
#include <iostream>
#include <sstream>
#include<cstdio>
#include<algorithm>
#define pow2(n) (1 << (n))

template<class T>
class AVLNode {
    private:
        T mVal;
        AVLNode<T> *mLeft;
        AVLNode<T> *mRight;
    public:
        AVLNode() {
            mVal = -1;
            mLeft = mRight = NULL;
        };
        AVLNode(const T &val) {
            this->mVal = val;
            this->mLeft = this->mRight = NULL;
        };
        AVLNode<T> *get_right() {return mRight; };
        AVLNode<T> *get_left() {return mLeft; };
        void set_left(AVLNode<T> *node) {mLeft = node; };
        void set_right(AVLNode<T> *node) {mRight = node; };
        T& get_val() {return mVal; };
        T ret_val() {return mVal; };
        void set_val(const T &val) {mVal = val; };
};

template<class T>
class AVLTree {
    private:
        AVLNode<T> *mRoot;

        /* Recommended, but not necessary helper function. */
        AVLNode<T>* put(AVLNode<T> *rover, const T &val);
        /* Recommended, but not necessary helper function. */
        void preorderString(AVLNode<T> *node, std::string &ret);
        void postorderString(AVLNode<T> *node, std::string &ret);
        void inorderString(AVLNode<T> *node, std::string &ret);
    public:

        std::string to_str(const T& value) {
            std::string ret;
            std::ostringstream ss;
            ss << value;
            ret = ss.str();
            return ret;
        };

        /* Creates an empty binary tree. */
        AVLTree();

        AVLNode<T>* copyNodes(AVLNode<T> *root);

        /* Does a deep copy of the tree. */
        AVLTree(const AVLTree<T> &tree);

        /* Add a given value to the Binary Tree. 
         * Must maintain ordering!
         */
        void put(const T &val);

        int maxDepth(AVLNode<T> *node);

        /* Returns the height of the binary tree. */
        int getHeight();

        /* Returns true if an item exists in the Binary Tree */
        bool contains(const T &val) const;

        bool contains(AVLNode<T> *node, const T &val) const;

        AVLNode<T>* findMin(AVLNode<T> *node);

        AVLNode<T>* remove(AVLNode<T> *node, const T &val);

        int difference(AVLNode<T> *node);

        
        AVLNode<T>* rr_rotat(AVLNode<T> *parent);
        
        AVLNode<T>* ll_rotat(AVLNode<T> *parent);
        
        AVLNode<T>* lr_rotat(AVLNode<T> *parent);
        
        AVLNode<T>* rl_rotat(AVLNode<T> *parent);
        
        AVLNode<T>* balance(AVLNode<T> *t);

        /* Removes a specific val from the Binary Tree.
         * Returns true if the value exists (and was removed.)
         * Otherwise, returns false.
         */
        bool remove(const T &val);

        /* Returns a string representation of the binary Tree in order. */
        std::string inorderString();

        /* Returns a string representation of the binary Tree pre order. */
        std::string preorderString();

        /* Returns a string representation of the binary Tree pre order. */
        std::string postorderString();

        void pullRoots(AVLNode<T> *root);

        /* Always free memory. */
        ~AVLTree();
};

/* Since AVLTree is templated, we include the .cpp.
 * Templated classes are not implemented until utilized (or explicitly 
 * declared.)
 */
#include "AVLTree.cpp"

#endif