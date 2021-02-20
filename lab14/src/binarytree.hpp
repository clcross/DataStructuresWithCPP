#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <string>
#include <sstream>

template<class T>
class BinaryTreeNode {
    private:
        T mVal;
        BinaryTreeNode<T> *mLeft;
        BinaryTreeNode<T> *mRight;
    public:
        BinaryTreeNode() {
            mVal = -1;
            mLeft = mRight = NULL;
        };
        BinaryTreeNode(const T &val) {
            this->mVal = val;
            this->mLeft = this->mRight = NULL;
        };
        BinaryTreeNode<T> *get_right() {return mRight; };
        BinaryTreeNode<T> *get_left() {return mLeft; };
        void set_left(BinaryTreeNode<T> *node) {mLeft = node; };
        void set_right(BinaryTreeNode<T> *node) {mRight = node; };
        T& get_val() {return mVal; };
        T ret_val() {return mVal; };
        void set_val(const T &val) {mVal = val; };
};

template<class T>
class BinaryTree {
    private:
        BinaryTreeNode<T> *mRoot;

        /* Recommended, but not necessary helper function. */
        void put(BinaryTreeNode<T> *rover, BinaryTreeNode<T> *newNode);
        /* Recommended, but not necessary helper function. */
        void inorderString(BinaryTreeNode<T> *node, std::string &ret);
    public:
        std::string to_str(const T& value) {
            std::string ret;
            std::ostringstream ss;
            ss << value;
            ret = ss.str();
            return ret;
        };

        /* Creates an empty binary tree. */
        BinaryTree();

        BinaryTreeNode<T>* copyNodes(BinaryTreeNode<T> *newNode);

        /* Does a deep copy of the tree. */
        BinaryTree(const BinaryTree<T> &tree);

        /* Add a given value to the Binary Tree. 
         * Must maintain ordering!
         * Do NOT do ANY balancing!
         */
        void put(const T &val);

        int maxDepth(BinaryTreeNode<T> *node);

        /* Returns the height for the binary tree. */
        int getHeight();

        /* Returns a string representation of the binary Tree in order. */
        std::string inorderString();

        /* Return the lowest common ancestor (LCA) of two values.
         * The LCA is the most immediate parent of both values.  For example:
         *      4
         *    /   \
         *   2     8
         *  / \   / \
         * 1   3 6   10
         * LCA(1, 3) = 2
         * LCA(1, 2) = 2
         * LCA(1, 6) = 4
         */
        int lca(int a, int b);

        int lca(BinaryTreeNode<T> *root, int n1, int n2);

        void pullRoots(BinaryTreeNode<T> *root);

        /* Always free memory. */
        ~BinaryTree();
};

/* Since BinaryTree is templated, we include the .cpp.
 * Templated classes are not implemented until utilized (or explicitly 
 * declared.)
 */
#include "binarytree.cpp"

#endif
