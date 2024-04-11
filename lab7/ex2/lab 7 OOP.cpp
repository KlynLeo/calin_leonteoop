#include <iostream>
#include "Tree.h"
using namespace std;
int main() {

    Tree<int> tree(10); 
    tree.add_node(nullptr, 10); 
    Node<int>* rootNode = tree.root; 

    tree.add_node(rootNode, 20);
    tree.add_node(rootNode, 30); 
    tree.add_node(rootNode->children[0], 15); 

    tree.insert(rootNode, 1, 25);
    tree.sort(rootNode, compare);

    int childrenCount = tree.count(rootNode); 
    cout << "Number of children of root node: " << childrenCount << endl;

    tree.delete_node(rootNode->children[0]); 
    int valueToFind = 30;

    Node<int>* foundNode = tree.find(rootNode, [](const int& a, const int& b) { return a == b; }, valueToFind);

    if (foundNode)
        cout << "Node with value " << valueToFind << " found." << endl;
    else
        cout << "Node with value " << valueToFind << " not found." << endl;

    return 0;
}
