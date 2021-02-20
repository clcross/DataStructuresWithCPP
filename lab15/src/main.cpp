#include <stdio.h>
#include <string>
#include "binarytree.hpp"

int main(int argc, char *argv[]) {
    BinaryTree<int> bt;

    int n1 = 14;
    bool temp = false;

    bt.put(5);
    bt.put(14);
    bt.put(2);
    bt.put(-30);
    bt.put(7);
    bt.put(19);
    bt.put(-3);
    std::cout << "string: " << bt.inorderString() << "\n";
    std::cout << "height: " << bt.getHeight() << "\n";
    if (bt.remove(n1)) {
        std::cout << "removing: " << n1 << "\n";
    }
    else {
        std::cout << "couldn't remove: " << n1 << "\n";
    }
    std::cout << "removestring: " << bt.inorderString() << "\n";
    std::cout << "removeheight: " << bt.getHeight() << "\n";
    std::cout << "count: " << bt.countInRange(4, 10) << "\n";
    if (bt.existsInRange(5, 5)) {
        std::cout << "exists\n";
    }
    else {
        std::cout << "doesn't exist\n";
    }
    BinaryTree<int> newBT = BinaryTree<int>(bt);
    std::cout << "copy BT\n";
    std::cout << newBT.inorderString();
    newBT.put(-4);
    std::cout << newBT.getHeight() << "\n";

    // bt.inorderTraversal(&bt.visited, 5);
    // std::cout << "\n";

}
