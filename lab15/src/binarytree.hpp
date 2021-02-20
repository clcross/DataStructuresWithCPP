#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>
#include <iostream>
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
        void preorderString(BinaryTreeNode<T> *node, std::string &ret);
        void postorderString(BinaryTreeNode<T> *node, std::string &ret);
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

        BinaryTreeNode<T>* copyNodes(BinaryTreeNode<T> *root);

        /* Does a deep copy of the tree. */
        BinaryTree(const BinaryTree<T> &tree);

        /* Add a given value to the Binary Tree. 
         * Must maintain ordering!
         */
        void put(const T &val);

        int maxDepth(BinaryTreeNode<T> *node);

        /* Returns the height of the binary tree. */
        int getHeight();

        /* Returns true if an item exists in the Binary Tree */
        bool contains(const T &val) const;

        bool contains(BinaryTreeNode<T> *node, const T &val) const;

        BinaryTreeNode<T>* findMin(BinaryTreeNode<T> *node);

        BinaryTreeNode<T>* remove(BinaryTreeNode<T> *node, const T &val);

        /* Removes a specific val from the Binary Tree.
         * Returns true if the value exists (and was removed.)
         * Otherwise, returns false.
         */
        bool remove(const T &val);

        bool existsInRange(BinaryTreeNode<T> *node, T min, T max) const;

        /* This method returns true iff there is a value in the tree 
         * >= min and <= max.  In other words, it returns true if there
         * is an item in the tree in the range [min, max]
         */
        bool existsInRange(T min, T max) const;

        int countInRange(BinaryTreeNode<T> *node, T min, T max) const;

        /* This is similar but it returns the number of items in the range. */
        int countInRange(T min, T max) const;

        /* Returns a string representation of the binary Tree in order. */
        std::string inorderString();

        /* Returns a string representation of the binary Tree pre order. */
        std::string preorderString();

        /* Returns a string representation of the binary Tree pre order. */
        std::string postorderString();

        void inorderTraversal(BinaryTreeNode<T> *node, bool dir);

        /* Does an inorder traversal of the Binary Search Tree calling
         * visit on each node.
         */
        void inorderTraversal(void (*visit) (T &item)) const;

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
