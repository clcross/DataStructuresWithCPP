#include <stdio.h>
#include <string>
#include "binarytree.hpp"

int main(int argc, char *argv[]) {
    BinaryTree<int> bt;

    int n2 = 7;
    int n1 = 19; 

    bt.put(5);
    bt.put(14);
    bt.put(2);
    bt.put(-30);
    bt.put(7);
    bt.put(19);
    bt.put(-3);
    std::cout << bt.inorderString();
    std::cout << bt.getHeight() << "\n";
    std::cout << bt.lca(n1, n2) << "\n";
    BinaryTree<int> newBT = BinaryTree<int>(bt);
    std::cout << "copy BT\n";
    std::cout << newBT.inorderString();
    newBT.put(-4);
    std::cout << newBT.getHeight() << "\n";

}
