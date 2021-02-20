// website used to get Splay implementation https://www.tutorialspoint.com/cplusplus-program-to-implement-splay-tree
#ifdef SPLAY_TREE_H
#define SPLAY_TREE_H
// #include "SplayTree.hpp"

#include <iostream>
#include <string>

template<class T>
SplayTree<T>::SplayTree() {
    mRoot = NULL;
}

template<class T>
SplayNode<T>* SplayTree<T>::copyNodes(SplayNode<T> *root) {  
    if(root == NULL) {
        return NULL;
    }
    
    SplayNode<T> *temp = new SplayNode<T>(root->get_val());
    // std::cout << temp->get_val() << " ";
    temp->set_left(copyNodes(root->get_left()));
    temp->set_right(copyNodes(root->get_right()));
    return temp;
}

template<class T>
SplayTree<T>::SplayTree(const SplayTree<T> &tree) {
    mRoot = copyNodes(tree.mRoot);
}

template<class T>
SplayNode<T>* SplayTree<T>::RR_Rotate(SplayNode<T> *k2) {
    SplayNode<T> *k1;
    k1 = k2->get_left();
    k2->set_left(k1->get_right());
    k1->set_right(k2);
    return k1;
}
template<class T>
SplayNode<T>* SplayTree<T>::LL_Rotate(SplayNode<T> *k2) {
    SplayNode<T> *k1;
    k1 = k2->get_right();
    k2->set_right(k1->get_left());
    k1->set_left(k2);
    return k1;
}

template<class T>
SplayNode<T>* SplayTree<T>::Splay(SplayNode<T> *rover, const T &val) {
    if (!rover) {
        return NULL;
    }

    SplayNode<T> header;
    header.set_left(NULL);
    header.set_right(NULL);
    SplayNode<T>* LeftTreeMax = &header;
    SplayNode<T>* RightTreeMin = &header;

    while (1) {
        if (val < rover->get_val()) {
            if (!rover->get_left()) {
                break;
            }
            if (val < rover->get_left()->get_val()) {
                rover = RR_Rotate(rover);
                if (!rover->get_left()) {
                    break;
                }
            }
            RightTreeMin->set_left(rover);
            RightTreeMin = RightTreeMin->get_left();
            rover = rover->get_left();
            RightTreeMin->set_left(NULL);
        }
        else if (val > rover->get_val()) {
            if (!rover->get_right()) {
                break;
            }
            if (val > rover->get_right()->get_val()) {
                rover = LL_Rotate(rover);
                if (!rover->get_right()) {
                    break;
                }
            }
            LeftTreeMax->set_right(rover);
            LeftTreeMax = LeftTreeMax->get_right();
            rover = rover->get_right();
            LeftTreeMax->set_right(NULL);
        }
        else {
            break;
        }
    }
    LeftTreeMax->set_right(rover->get_left());
    RightTreeMin->set_left(rover->get_right());
    rover->set_left(header.get_right());
    rover->set_right(header.get_left());
    return rover;
}

template<class T>
SplayNode<T>* SplayTree<T>::put(SplayNode<T> *rover, const T &val) {
    static SplayNode<T>* p_node = NULL;
    if (!p_node) {
        p_node = new SplayNode<T>(val);
    }
    else {
        p_node->set_val(val);
    }
    if (!rover) {
        rover = p_node;
        p_node = NULL;
        return rover;
    }

    rover = Splay(rover, val);

    if (val < rover->get_val()) {
        p_node->set_left(rover->get_left());
        p_node->set_right(rover);
        rover->set_left(NULL);
        rover = p_node;
    }
    else if (val > rover->get_val()) {
        p_node->set_right(rover->get_right());
        p_node->set_left(rover);
        rover->set_right(NULL);
        rover = p_node;
    }
    else {
        return rover;
    }
    p_node = NULL;
    return rover;
}

template<class T>
void SplayTree<T>::put(const T &val) {
    mRoot = put(mRoot, val);
}

template<class T>
int SplayTree<T>::difference(SplayNode<T> *node) {
    int l_height = maxDepth(node->get_left());
    int r_height = maxDepth(node->get_right());
    int b_factor = l_height - r_height;
    return b_factor;
}

template<class T>
int SplayTree<T>::maxDepth(SplayNode<T> *node){
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
int SplayTree<T>::getHeight() {
    return maxDepth(mRoot);
}

template<class T>
bool SplayTree<T>::contains(SplayNode<T> *node, const T &val) const{
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
bool SplayTree<T>::contains(const T &val) const{
    return contains(mRoot, val);
}

template<class T>
SplayNode<T>* SplayTree<T>::findMin(SplayNode<T> *node) { 
    SplayNode<T> *current = node; 
  
    while (current && current->get_left() != NULL) {
        current = current->get_left(); 
    }
    return current; 
} 

template<class T>
SplayNode<T>* SplayTree<T>::remove(SplayNode<T> *node, const T &val) { 
    SplayNode<T>* temp;
    if (!node) {
        return NULL;
    }

    node = Splay(node, val);

    if (val != node->get_val()) {
        return node;
    }
    else {
        if (!node->get_left()) {
            temp = node;
            node = node->get_right();
        }
        else {
            temp = node;
            node = Splay(node->get_left(), val);
            node->set_right(temp->get_right());
        }

        // std::cout << "temp val: " << temp->get_val() << "\n";
        free(temp);
        // std::cout << "root val: " << node->get_val() << "\n";
        return node;
    }
} 

template<class T>
bool SplayTree<T>::remove(const T &val) {
    if (contains(mRoot, val) == false) {
        return false;
    }
    else {
        mRoot = remove(mRoot, val);
        // std::cout << "root2 val: " << mRoot->get_val() << "\n";
        return true;
    }
}

template<class T>
void SplayTree<T>::preorderString(SplayNode<T> *node, std::string &ret) {
    if (!node) { return; }
    ret += to_str(node->get_val());
    ret += " ";
    preorderString(node->get_left(), ret);
    preorderString(node->get_right(), ret);
}

/* Returns a string representation of the binary Tree pre order. */
template<class T>
std::string SplayTree<T>::preorderString(){
    std::string tree = "";
    preorderString(mRoot, tree);
    return tree;
}

template<class T>
void SplayTree<T>::postorderString(SplayNode<T> *node, std::string &ret) {
    if (!node) { return; }
    preorderString(node->get_left(), ret);
    preorderString(node->get_right(), ret);
    ret += to_str(node->get_val());
    ret += " ";
}

/* Returns a string representation of the binary Tree pre order. */
template<class T>
std::string SplayTree<T>::postorderString(){
    std::string tree = "";
    postorderString(mRoot, tree);
    return tree;
}

template<class T>
void SplayTree<T>::inorderString(SplayNode<T> *node, std::string &ret) {
    if (!node) { return; }
    inorderString(node->get_left(), ret);
    ret += to_str(node->get_val());
    ret += " ";
    inorderString(node->get_right(), ret);
}

template<class T>
std::string SplayTree<T>::inorderString() {
    std::string tree = "";
    inorderString(mRoot, tree);
    return tree;
}

template<class T>
void SplayTree<T>::pullRoots(SplayNode<T> *root) {
    if (root) {
        pullRoots(root->get_left());
        pullRoots(root->get_right());
        delete root;
    }
}

template<class T>
SplayTree<T>::~SplayTree() {
    pullRoots(mRoot);
}


#endif