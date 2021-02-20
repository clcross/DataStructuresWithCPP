// website used to get avl implementation https://www.tutorialspoint.com/cplusplus-program-to-implement-avl-tree
#ifdef AVL_TREE_H
#define AVL_TREE_H
// #include "AVLTree.hpp"

#include <iostream>
#include <string>

template<class T>
AVLTree<T>::AVLTree() {
    mRoot = NULL;
}

template<class T>
AVLNode<T>* AVLTree<T>::copyNodes(AVLNode<T> *root) {  
    if(root == NULL) {
        return NULL;
    }
    
    AVLNode<T> *temp = new AVLNode<T>(root->get_val());
    // std::cout << temp->get_val() << " ";
    temp->set_left(copyNodes(root->get_left()));
    temp->set_right(copyNodes(root->get_right()));
    return temp;
}

template<class T>
AVLTree<T>::AVLTree(const AVLTree<T> &tree) {
    mRoot = copyNodes(tree.mRoot);
}

template<class T>
AVLNode<T>* AVLTree<T>::rr_rotat(AVLNode<T> *parent) {
    AVLNode<T> *t;
    t = parent->get_right();
    parent->set_right(t->get_left());
    t->set_left(parent);
    // std::cout << "Right-Right Rotation";
    return t;
}
template<class T>
AVLNode<T>* AVLTree<T>::ll_rotat(AVLNode<T> *parent) {
    AVLNode<T> *t;
    t = parent->get_left();
    parent->set_left(t->get_right());
    t->set_right(parent);
    // std::cout << "Left-Left Rotation";
    return t;
}
template<class T>
AVLNode<T>* AVLTree<T>::lr_rotat(AVLNode<T> *parent) {
    AVLNode<T> *t;
    t = parent->get_left();
    parent->set_left(rr_rotat(t));
    // std::cout << "Left-Right Rotation";
    return ll_rotat(parent);
}
template<class T>
AVLNode<T>* AVLTree<T>::rl_rotat(AVLNode<T> *parent) {
    AVLNode<T> *t;
    t = parent->get_right();
    parent->set_right(ll_rotat(t));
    // std::cout << "Right-Left Rotation";
    return rr_rotat(parent);
}
template<class T>
AVLNode<T>* AVLTree<T>::balance(AVLNode<T> *t) {
    int bal_factor = difference(t);
    if (bal_factor > 1) {
        if (difference(t->get_left()) > 0)
            t = ll_rotat(t);
        else
            t = lr_rotat(t);
    } else if (bal_factor < -1) {
        if (difference(t->get_right()) > 0)
            t = rl_rotat(t);
        else
            t = rr_rotat(t);
    }
    return t;
}

template<class T>
AVLNode<T>* AVLTree<T>::put(AVLNode<T> *rover, const T &val) {
    if (rover == NULL) {
        rover = new AVLNode<T>(val);
        return rover;
    }
    else if (val < rover->get_val()) {
        rover->set_left(put(rover->get_left(), val));
        rover = balance(rover);
    }
    else if (val >= rover->get_val()) {
        rover->set_right(put(rover->get_right(), val));
        rover = balance(rover);
    } 
    return rover;
}

template<class T>
void AVLTree<T>::put(const T &val) {
    mRoot = put(mRoot, val);
}

template<class T>
int AVLTree<T>::difference(AVLNode<T> *node) {
    int l_height = maxDepth(node->get_left());
    int r_height = maxDepth(node->get_right());
    int b_factor = l_height - r_height;
    return b_factor;
}

template<class T>
int AVLTree<T>::maxDepth(AVLNode<T> *node){
    int h = 0;
    if (node != NULL) {
        int l_height = maxDepth(node->get_left());
        int r_height = maxDepth(node->get_right());
        int max_height = std::max(l_height, r_height);
        h = max_height + 1;
    }
   return h;
}

template<class T>
int AVLTree<T>::getHeight() {
    return maxDepth(mRoot);
}

template<class T>
bool AVLTree<T>::contains(AVLNode<T> *node, const T &val) const{
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
bool AVLTree<T>::contains(const T &val) const{
    return contains(mRoot, val);
}

template<class T>
AVLNode<T>* AVLTree<T>::findMin(AVLNode<T> *node) { 
    AVLNode<T> *current = node; 
  
    while (current && current->get_left() != NULL) {
        current = current->get_left(); 
    }
    return current; 
} 

template<class T>
AVLNode<T>* AVLTree<T>::remove(AVLNode<T> *node, const T &val) { 
    if (node == NULL) {return node;} 
  
    if (val < node->get_val()) {
        node->set_left(remove(node->get_left(), val));
    }
    else if (val > node->get_val()) {
        node->set_right(remove(node->get_right(), val)); 
    }
    else { 
        if (node->get_left() == NULL) { 
            AVLNode<T> *temp = new AVLNode<T>();
            temp = node->get_right(); 
            free(node); 
            return temp; 
        } 
        else if (node->get_right() == NULL) { 
            AVLNode<T> *temp = new AVLNode<T>();
            temp = node->get_left(); 
            free(node); 
            return temp; 
        } 
  
        AVLNode<T> *temp = findMin(node->get_right()); 
  
        node->set_val(temp->get_val()); 
        
        node->set_right(remove(node->get_right(), temp->get_val())); 
    } 
    return node; 
} 

template<class T>
bool AVLTree<T>::remove(const T &val) {
    if (contains(mRoot, val) == false) {
        return false;
    }
    else {
        mRoot = remove(mRoot, val);
        return true;
    }
}

template<class T>
void AVLTree<T>::preorderString(AVLNode<T> *node, std::string &ret) {
    if (!node) { return; }
    ret += to_str(node->get_val());
    ret += " ";
    preorderString(node->get_left(), ret);
    preorderString(node->get_right(), ret);
}

/* Returns a string representation of the binary Tree pre order. */
template<class T>
std::string AVLTree<T>::preorderString(){
    std::string tree = "";
    preorderString(mRoot, tree);
    return tree;
}

template<class T>
void AVLTree<T>::postorderString(AVLNode<T> *node, std::string &ret) {
    if (!node) { return; }
    preorderString(node->get_left(), ret);
    preorderString(node->get_right(), ret);
    ret += to_str(node->get_val());
    ret += " ";
}

/* Returns a string representation of the binary Tree pre order. */
template<class T>
std::string AVLTree<T>::postorderString(){
    std::string tree = "";
    postorderString(mRoot, tree);
    return tree;
}

template<class T>
void AVLTree<T>::inorderString(AVLNode<T> *node, std::string &ret) {
    if (!node) { return; }
    inorderString(node->get_left(), ret);
    ret += to_str(node->get_val());
    ret += " ";
    inorderString(node->get_right(), ret);
}

template<class T>
std::string AVLTree<T>::inorderString() {
    std::string tree = "";
    inorderString(mRoot, tree);
    return tree;
}

template<class T>
void AVLTree<T>::pullRoots(AVLNode<T> *root) {
    if (root) {
        pullRoots(root->get_left());
        pullRoots(root->get_right());
        delete root;
    }
}

template<class T>
AVLTree<T>::~AVLTree() {
    pullRoots(mRoot);
}


#endif