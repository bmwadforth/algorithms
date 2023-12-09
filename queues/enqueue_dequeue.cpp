#include <iostream>

#define SIZE 5 // Size of the queue (can be adjusted)

class Queue {
private:
    int front, rear, itemCount;
    int queue[SIZE];

public:
    Queue() : front(-1), rear(-1), itemCount(0) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return itemCount == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return itemCount == SIZE;
    }

    // Function to add an element to the queue (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        itemCount++;
    }

    // Function to remove an element from the queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return -1; // Return -1 or handle empty queue condition accordingly
        }

        int removedItem = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        itemCount--;
        return removedItem;
    }
};

int main() {
    Queue q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    std::cout << "Dequeued item: " << q.dequeue() << std::endl;

    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(30);

    std::cout << "Dequeued item: " << q.dequeue() << std::endl;

    return 0;
}
