# Queues

Queues are linear data structures that follow the First In, First Out (FIFO) principle. Elements are added at the rear (enqueue) and removed from the front (dequeue). They model real-world scenarios like waiting lines.

Example usage:
```c++
#include <iostream>
#include <queue>

int main() {
    // Creating a queue
    std::queue<int> myQueue;

    // Enqueue elements
    myQueue.push(5);
    myQueue.push(10);
    myQueue.push(15);

    // Display the front element
    std::cout << "Front element: " << myQueue.front() << std::endl;

    // Dequeue elements
    while (!myQueue.empty()) {
        std::cout << "Dequeued: " << myQueue.front() << std::endl;
        myQueue.pop();
    }

    return 0;
}
```

Common algorithms and operations used with queues include:

1. Enqueue and Dequeue:
   Enqueue: Adding an element to the rear of the queue.
   Dequeue: Removing the front element from the queue.
2. Front and Empty Check:
   Front: Accessing the front element without removing it.
   Empty: Checking if the queue is empty.
3. Size and Clear:
   Size: Retrieving the number of elements in the queue.
   Clear: Removing all elements from the queue.
4. Circular Queue (or Ring Buffer):
   Implementing a fixed-size circular queue, useful in situations with limited space.
5. Priority Queue:
   A variant of the queue where elements have priorities and are dequeued based on their priority.
6. Breadth-first Search (BFS):
   Using a queue in the BFS algorithm for traversing graphs or trees level by level.
   Queues are essential in many computer science applications, including process scheduling in operating systems, network data packet handling, implementing breadth-first search in graph algorithms, and more. Their FIFO behavior makes them valuable in scenarios where the order of processing is crucial.