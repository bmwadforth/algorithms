# Binary Trees

Binary trees are hierarchical data structures composed of nodes where each node has at most two children, referred to as the left child and the right child. Each node can have data and references (pointers) to its left and right children.

Example usage:
```c++
#include <iostream>

// Node structure for a binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int main() {
    // Creating a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Visual representation of the binary tree
    std::cout << "     1" << std::endl;
    std::cout << "    / \\" << std::endl;
    std::cout << "   2   3" << std::endl;
    std::cout << "  /    \\" << std::endl;
    std::cout << " 4      5" << std::endl;

    return 0;
}
```

Common algorithms and operations used with binary trees include:

1. Traversal:
   In-order Traversal: Visit left subtree, then the root, then the right subtree.
   Pre-order Traversal: Visit the root, then the left subtree, then the right subtree.
   Post-order Traversal: Visit the left subtree, then the right subtree, then the root.
2. Search and Insertion:
   Search: Searching for a specific value in the binary tree.
   Insertion: Inserting a node with a specific value into the binary tree.
3. Deletion:
   Deletion by Value: Removing a node with a specific value from the binary tree.
4. Height and Size:
   Height: Calculating the height of the binary tree (maximum depth).
   Size: Counting the number of nodes in the binary tree.
5. Check and Validation:
   Check if Binary Tree is BST: Determining if the binary tree is a Binary Search Tree.
   Check if Balanced: Checking if the binary tree is balanced (difference in height between left and right subtrees is not more than 1).
6. Level-order Traversal (Breadth-first Search):
   Level-order Traversal: Visiting nodes level by level from left to right.
   These algorithms are fundamental in understanding, manipulating, and managing binary trees efficiently, forming the basis for various tree-based data structure operations and applications.