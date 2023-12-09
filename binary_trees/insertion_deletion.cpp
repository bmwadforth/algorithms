#include <iostream>
#include <queue>

// Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void insertNode(Node* root, int value) {
    std::queue<Node*> q;
    q.push(root);

    // Do level order traversal until we find an empty place
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = new Node(value);
            break;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = new Node(value);
            break;
        } else {
            q.push(temp->right);
        }
    }
}

Node* deleteDeepest(Node* root, Node* deepest) {
    std::queue<Node*> q;
    q.push(root);

    Node* temp = nullptr;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == deepest) {
            temp = nullptr;
            delete deepest;
            return nullptr;
        }
        if (temp->right) {
            if (temp->right == deepest) {
                temp->right = nullptr;
                delete deepest;
                return root;
            } else {
                q.push(temp->right);
            }
        }
        if (temp->left) {
            if (temp->left == deepest) {
                temp->left = nullptr;
                delete deepest;
                return root;
            } else {
                q.push(temp->left);
            }
        }
    }
    return root;
}

void deleteNode(Node* root, int value) {
    if (!root) {
        std::cout << "Tree is empty.\n";
        return;
    }

    if (!root->left && !root->right) {
        if (root->data == value) {
            delete root;
            root = nullptr;
            std::cout << "Node deleted.\n";
            return;
        } else {
            std::cout << "Value not found in the tree.\n";
            return;
        }
    }

    std::queue<Node*> q;
    q.push(root);
    Node* temp;
    Node* keyNode = nullptr;

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->data == value) {
            keyNode = temp;
        }

        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }

    if (keyNode) {
        int x = temp->data;
        root = deleteDeepest(root, temp);
        keyNode->data = x;
        std::cout << "Node deleted.\n";
    } else {
        std::cout << "Value not found in the tree.\n";
    }
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout << "Inorder Traversal before insertion: ";
    inorderTraversal(root);
    std::cout << std::endl;

    int insertValue = 6;
    insertNode(root, insertValue);

    std::cout << "Inorder Traversal after insertion of " << insertValue << ": ";
    inorderTraversal(root);
    std::cout << std::endl;

    int deleteValue = 3;
    deleteNode(root, deleteValue);

    std::cout << "Inorder Traversal after deletion of " << deleteValue << ": ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
