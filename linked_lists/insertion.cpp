#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to insert a new node at the beginning of the linked list
Node* insertNode(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    return newNode; // Returning the new head of the list
}

// Function to traverse and print the linked list
void traverseLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    // Inserting elements into the linked list
    head = insertNode(head, 5);
    head = insertNode(head, 10);
    head = insertNode(head, 15);

    // Traversing and printing the linked list
    traverseLinkedList(head);

    return 0;
}
