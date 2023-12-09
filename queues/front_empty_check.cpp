#include <iostream>

#define SIZE 5 // Size of the queue (can be adjusted)

class Queue {
private:
    int front, rear, itemCount;
    int queue[SIZE];

public:
    Queue() : front(-1), rear(-1), itemCount(0) {}

    bool isEmpty() {
        return itemCount == 0;
    }

    bool isFull() {
        return itemCount == SIZE;
    }

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

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return -1;
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

    int frontValue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No front value.\n";
            return -1;
        }
        return queue[front];
    }
};

int main() {
    Queue q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    std::cout << "Front value: " << q.frontValue() << std::endl;
    std::cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
