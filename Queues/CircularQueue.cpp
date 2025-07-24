#include <bits/stdc++.h>
using namespace std;
class CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }
    // Enqueues 'X' into the queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int value) {
        // Check if the queue is full
        if ((rear + 1) % size == front) {
            return false; // Queue is full
        }
        // First element being inserted
        if (front == -1) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        return true;
    }
    // Dequeues top element from queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue() {
        if (front == -1) {
            return -1; // Queue is empty
        }
        int ans = arr[front];
        arr[front] = -1; // Optional: Clear the dequeued position
        if (front == rear) {
            front = rear = -1; // Queue is now empty
        }
        else {
            front = (front + 1) % size;
        }
        return ans;
    }
    // Destructor to free the allocated memory
    ~CircularQueue() {
        delete[] arr;
    }
    // Optional: method to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }
    // Optional: method to check if the queue is full
    bool isFull() {
        return (rear + 1) % size == front;
    }
};

int main() {
    CircularQueue q(5);
    // Example usage
    cout << q.enqueue(1) << endl; // 1
    cout << q.enqueue(2) << endl; // 1
    cout << q.enqueue(3) << endl; // 1
    cout << q.enqueue(4) << endl; // 1
    cout << q.enqueue(5) << endl; // 1
    cout << q.enqueue(6) << endl; // 0 (queue is full)
    cout << q.dequeue() << endl; // 1
    cout << q.dequeue() << endl; // 2
    cout << q.enqueue(6) << endl; // 1
    return 0;
}