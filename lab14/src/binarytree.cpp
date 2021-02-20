#ifdef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <string>

template<class T>
BinaryTree<T>::BinaryTree() {
    mRoot = NULL;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::copyNodes(BinaryTreeNode<T> *root) {  
    if(root == NULL) {
        return NULL;
    }
    
    BinaryTreeNode<T> *temp = new BinaryTreeNode<T>(root->get_val());
    // std::cout << temp->get_val() << " ";
    temp->set_left(copyNodes(root->get_left()));
    temp->set_right(copyNodes(root->get_right()));
    return temp;
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &tree) {
    mRoot = copyNodes(tree.mRoot);
}


template<class T>
void BinaryTree<T>::put(BinaryTreeNode<T> *rover, BinaryTreeNode<T> *newNode) {
    if (rover == NULL || newNode == NULL) { return; }

    if (rover->ret_val() == newNode->get_val()) {
	   rover = rover->get_left();
	}

    if (rover->get_val() < newNode->get_val()) {
        if (rover->get_right() == NULL) {
            rover->set_right(newNode);
            return;
        }
        put(rover->get_right(), newNode);
    }
    else if (rover->get_val() > newNode->get_val()) {
        if (rover->get_left() == NULL) {
            rover->set_left(newNode);
            return;
        }
        put(rover->get_left(), newNode);
    }
}

template<class T>
void BinaryTree<T>::put(const T &val) {
    BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>(val);
    if (mRoot == NULL) {
        mRoot = newNode;
        return;
    }
    put(mRoot, newNode);
}

template<class T>
int BinaryTree<T>::maxDepth(BinaryTreeNode<T> *node){
    if (node == NULL) {
        return 0;
    }
    
    int lDepth = maxDepth(node->get_left());
    int rDepth = maxDepth(node->get_right());
    if (lDepth > rDepth) {
        return lDepth + 1;
    }
    else {
        return rDepth + 1;
    }
}

template<class T>
int BinaryTree<T>::getHeight() {
    return maxDepth(mRoot);
}

template<class T>
void BinaryTree<T>::inorderString(BinaryTreeNode<T> *node, std::string &ret) {
    if (!node) { return; }
    inorderString(node->get_left(), ret);
    ret += to_str(node->get_val());
    ret += " ";
    inorderString(node->get_right(), ret);
}

template<class T>
std::string BinaryTree<T>::inorderString() {
    std::string tree = "";
    inorderString(mRoot, tree);
    return tree;
}

template<class T>
int BinaryTree<T>::lca(BinaryTreeNode<T> *root, int n1, int n2) {  
    if (root == NULL) {
        return NULL;
    }  
  
    if (root->get_val() > n1 && root->get_val() > n2) { 
        return lca(root->get_left(), n1, n2);  
    }
  
    if (root->get_val() < n1 && root->get_val() < n2) { 
        return lca(root->get_right(), n1, n2);
    } 
  
    return root->get_val();  
}

template<class T>
int BinaryTree<T>::lca(int a, int b) {
    return lca(mRoot, a, b);
}

template<class T>
void BinaryTree<T>::pullRoots(BinaryTreeNode<T> *root) {
    if (root) {
        pullRoots(root->get_left());
        pullRoots(root->get_right());
        delete root;
    }
}

template<class T>
BinaryTree<T>::~BinaryTree() {
    pullRoots(mRoot);
}


#endif
