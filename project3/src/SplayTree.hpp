// website used to get Splay implementation https://www.tutorialspoint.com/cplusplus-program-to-implement-splay-tree
#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include <string>
#include <iostream>
#include <sstream>
#include<cstdio>
#include<algorithm>
#define pow2(n) (1 << (n))

template<class T>
class SplayNode {
    private:
        T mVal;
        SplayNode<T> *mLeft;
        SplayNode<T> *mRight;
    public:
        SplayNode() {
            mVal = -1;
            mLeft = mRight = NULL;
        };
        SplayNode(const T &val) {
            this->mVal = val;
            this->mLeft = this->mRight = NULL;
        };
        SplayNode<T> *get_right() {return mRight; };
        SplayNode<T> *get_left() {return mLeft; };
        void set_left(SplayNode<T> *node) {mLeft = node; };
        void set_right(SplayNode<T> *node) {mRight = node; };
        T& get_val() {return mVal; };
        T ret_val() {return mVal; };
        void set_val(const T &val) {mVal = val; };
};

template<class T>
class SplayTree {
    private:
        SplayNode<T> *mRoot;

        /* Recommended, but not necessary helper function. */
        SplayNode<T>* put(SplayNode<T> *rover, const T &val);
        /* Recommended, but not necessary helper function. */
        void preorderString(SplayNode<T> *node, std::string &ret);
        void postorderString(SplayNode<T> *node, std::string &ret);
        void inorderString(SplayNode<T> *node, std::string &ret);
    public:

        std::string to_str(const T& value) {
            std::string ret;
            std::ostringstream ss;
            ss << value;
            ret = ss.str();
            return ret;
        };

        /* Creates an empty binary tree. */
        SplayTree();

        SplayNode<T>* copyNodes(SplayNode<T> *root);

        /* Does a deep copy of the tree. */
        SplayTree(const SplayTree<T> &tree);

        /* Add a given value to the Binary Tree. 
         * Must maintain ordering!
         */
        void put(const T &val);

        int maxDepth(SplayNode<T> *node);

        /* Returns the height of the binary tree. */
        int getHeight();

        /* Returns true if an item exists in the Binary Tree */
        bool contains(const T &val) const;

        bool contains(SplayNode<T> *node, const T &val) const;

        SplayNode<T>* findMin(SplayNode<T> *node);

        SplayNode<T>* remove(SplayNode<T> *node, const T &val);

        int difference(SplayNode<T> *node);

        
        SplayNode<T>* RR_Rotate(SplayNode<T> *k2);
        
        SplayNode<T>* LL_Rotate(SplayNode<T> *k2);

        SplayNode<T>* Splay(SplayNode<T> *rover, const T &val);

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

        void pullRoots(SplayNode<T> *root);

        /* Always free memory. */
        ~SplayTree();
};

/* Since SplayTree is templated, we include the .cpp.
 * Templated classes are not implemented until utilized (or explicitly 
 * declared.)
 */
#include "SplayTree.cpp"

#endif