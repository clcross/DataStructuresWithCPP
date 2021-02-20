#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

class BSTNode {
    private:
        int mVal;
        BSTNode *mLeft;
        BSTNode *mRight;
    public:
        BSTNode();
        BSTNode(const int val, BSTNode *left, BSTNode *right);
        BSTNode *get_right();
        BSTNode *get_left();
        void set_left(BSTNode *node);
        void set_right(BSTNode *node);
        int get_val();
        void set_val(const int val);
};

class BST {
    private:
        BSTNode *mRoot;
    public:
        BST();
        void add(int val);
        bool remove(int val);
        bool contains(int val);
        void print();
};

#endif
