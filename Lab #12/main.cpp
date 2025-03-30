#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
    BinaryTree<int> tree;

    cout << "Inserting nodes with 12, 9, 10, 15, 18, 17, 20\n" << endl;

    tree.insertNode(12);
    tree.insertNode(9);
    tree.insertNode(10);
    tree.insertNode(15);
    tree.insertNode(18);
    tree.insertNode(17);
    tree.insertNode(20);

    cout << "The number of nodes in the tree is now: " <<
    tree.numNodes() << "\n" << endl;

    tree.displayInOrder();

    cout << endl;
    cout << endl;


    cout << "now deleting 9 from the tree...\n";
    tree.remove(9);

    cout << "now deleting 15 from the tree...\n";
    tree.remove(15);


    cout << endl;

    cout << "The number of nodes in the tree is now: " <<
    tree.numNodes() << "\n" << endl;

    cout << "Here are the values in the tree in order:\n";
    tree.displayInOrder();

    cout << endl;
    cout << endl;

    cout << "Here are the values in the tree in POST order:\n";
    tree.displayPostOrder();

    cout << endl;
    cout << endl;

    cout << "\tTree" << endl;
    cout << "\t |" << endl;
    cout << "\t 12" << endl;
    cout << "\t/  \\" << endl;
    cout << "  10   18" << endl;
    cout << "\t   / \\ " << endl;
    cout << "\t  17  20" << endl;

    cout << "Binary Tree - Prabhdeep Singh" << endl;

    return 0;
}
