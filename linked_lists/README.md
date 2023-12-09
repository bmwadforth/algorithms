# Linked Lists

Linked lists are linear data structures composed of nodes where each node points to the next node in the sequence. Unlike arrays, linked lists do not have a fixed size, and their elements are not stored in contiguous memory locations.

Example usage:
```c++
#include <iostream>

// Node structure for a singly linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to print elements of a linked list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Print the linked list
    std::cout << "Linked List: ";
    printList(head);

    return 0;
}
```

Common algorithms and operations used with linked lists include:

1. Traversal:
   Print: Traversing the linked list to print all elements.
   Search: Searching for a specific value in the linked list.
2. Insertion:
   Insert at Head: Adding a node at the beginning of the linked list.
   Insert at Tail: Adding a node at the end of the linked list.
   Insert at Given Position: Inserting a node at a specified position in the linked list.
3. Deletion:
   Delete at Head: Removing the first node from the linked list.
   Delete at Tail: Removing the last node from the linked list.
   Delete by Value: Removing a node with a specific value from the linked list.
   Delete at Given Position: Removing a node at a specified position in the linked list.
4. Reversal:
   Reverse: Reversing the linked list to change the order of elements.
5. Cycle Detection:
   Detect Cycle: Determining if a linked list has a cycle or is cyclic.
6. Merge and Split:
   Merge: Merging two sorted linked lists into a single sorted linked list.
   Split: Splitting a linked list into two halves.
   These algorithms are essential for manipulating and managing linked lists efficiently, and they form the basis for various data structure operations and applications.