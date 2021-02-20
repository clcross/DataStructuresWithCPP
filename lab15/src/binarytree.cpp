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
bool BinaryTree<T>::contains(BinaryTreeNode<T> *node, const T &val) const{
    if (!node) {return false;} 

    if (node->get_val() == val) {
        return true;
    }
  
    if (node->get_val() < val) {
        return contains(node->get_right(), val);
    }
    else if (node->get_val() > val) {
        return contains(node->get_left(), val); 
    }
    else {
        return false;
    }
}

/* Returns true if an item exists in the Binary Tree */
template<class T>
bool BinaryTree<T>::contains(const T &val) const{
    return contains(mRoot, val);
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::findMin(BinaryTreeNode<T> *node) { 
    BinaryTreeNode<T> *current = node; 
  
    while (current && current->get_left() != NULL) {
        current = current->get_left(); 
    }
    return current; 
} 

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::remove(BinaryTreeNode<T> *node, const T &val) { 
    if (node == NULL) {return node;} 
  
    if (val < node->get_val()) {
        node->set_left(remove(node->get_left(), val));
    }
    else if (val > node->get_val()) {
        node->set_right(remove(node->get_right(), val)); 
    }
    else { 
        if (node->get_left() == NULL) { 
            BinaryTreeNode<T> *temp = new BinaryTreeNode<T>();
            temp = node->get_right(); 
            free(node); 
            return temp; 
        } 
        else if (node->get_right() == NULL) { 
            BinaryTreeNode<T> *temp = new BinaryTreeNode<T>();
            temp = node->get_left(); 
            free(node); 
            return temp; 
        } 
  
        BinaryTreeNode<T> *temp = findMin(node->get_right()); 
  
        node->set_val(temp->get_val()); 
        
        node->set_right(remove(node->get_right(), temp->get_val())); 
    } 
    return node; 
} 

template<class T>
bool BinaryTree<T>::remove(const T &val) {
    if (contains(mRoot, val) == false) {
        return false;
    }
    else {
        mRoot = remove(mRoot, val);
        return true;
    }
}

template<class T>
bool BinaryTree<T>::existsInRange(BinaryTreeNode<T> *node, T min, T max) const{
    if (!node) {return false;} 

    if (node->get_val() == max && node->get_val() == min) {
        return true;
    }

    if (node->get_val() <= max && node->get_val() >= min) {
        return true;
    }
    else if (node->get_val() > max) {
        return existsInRange(node->get_left(), min, max);
    }
    else if (node->get_val() < min) {
        return existsInRange(node->get_right(), min, max); 
    }
    else {
        return false; 
    }
}

/* This method returns true iff there is a value in the tree 
* >= min and <= max.  In other words, it returns true if there
* is an item in the tree in the range [min, max]
*/
template<class T>
bool BinaryTree<T>::existsInRange(T min, T max) const{
    return existsInRange(mRoot, min, max);
}

template<class T>
int BinaryTree<T>::countInRange(BinaryTreeNode<T> *node, T min, T max) const{
    if (!node) {return 0;} 

    if (node->get_val() == max && node->get_val() == min) {
        return 1;
    }
  
    if (node->get_val() <= max && node->get_val() >= min) {
        return 1 + countInRange(node->get_left(), min, max) + countInRange(node->get_right(), min, max); 
    }
    else if (node->get_val() < min) {
        return countInRange(node->get_right(), min, max); 
    }
    else {
        return countInRange(node->get_left(), min, max); 
    }
}

/* This is similar but it returns the number of items in the range. */
template<class T>
int BinaryTree<T>::countInRange(T min, T max) const{
    return countInRange(mRoot, min, max);
}

template<class T>
void BinaryTree<T>::preorderString(BinaryTreeNode<T> *node, std::string &ret) {
    if (!node) { return; }
    ret += to_str(node->get_val());
    ret += " ";
    preorderString(node->get_left(), ret);
    preorderString(node->get_right(), ret);
}

/* Returns a string representation of the binary Tree pre order. */
template<class T>
std::string BinaryTree<T>::preorderString(){
    std::string tree = "";
    preorderString(mRoot, tree);
    return tree;
}

template<class T>
void BinaryTree<T>::postorderString(BinaryTreeNode<T> *node, std::string &ret) {
    if (!node) { return; }
    preorderString(node->get_left(), ret);
    preorderString(node->get_right(), ret);
    ret += to_str(node->get_val());
    ret += " ";
}

/* Returns a string representation of the binary Tree pre order. */
template<class T>
std::string BinaryTree<T>::postorderString(){
    std::string tree = "";
    postorderString(mRoot, tree);
    return tree;
}

template<class T>
void BinaryTree<T>::inorderTraversal(BinaryTreeNode<T> *node, bool dir) {
    if (!node) { return; }
    if (dir) {
        inorderTraversal(node->get_left(), dir);
    }
    else {
        inorderTraversal(node->get_right(), dir);
    }
}

/* Does an inorder traversal of the Binary Search Tree calling
* visit on each node.
*/
template<class T>
void BinaryTree<T>::inorderTraversal(void (*visit) (T &item)) const{
    inorderTraversal(mRoot, true);
    (*visit);
    inorderTraversal(mRoot, false);
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
