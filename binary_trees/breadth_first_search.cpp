#include <iostream>
#include <queue>

// Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void breadthFirstSearch(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<Node*> queue;
    queue.push(root);

    while (!queue.empty()) {
        Node* current = queue.front();
        std::cout << current->data << " ";
        queue.pop();

        if (current->left != nullptr) {
            queue.push(current->left);
        }
        if (current->right != nullptr) {
            queue.push(current->right);
        }
    }
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    std::cout << "Breadth-First Search (BFS) traversal: ";
    breadthFirstSearch(root);
    std::cout << std::endl;

    return 0;
}
