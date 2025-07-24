#include<bits/stdc++.h>
using namespace std;
class Deque {
    int* arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }
    // Destructor to free the allocated memory
    ~Deque() {
        delete[] arr;
    }
    // Pushes 'X' in the front of the deque.
    bool pushFront(int x) {
        if (isFull()) {
            return false;
        }
        if (front == -1) { // If deque is empty
            front = rear = 0;
        }
        else if (front == 0) { // Wrap around
            front = size - 1;
        }
        else {
            front--;
        }
        arr[front] = x;
        return true;
    }
    // Pushes 'X' in the back of the deque.
    bool pushRear(int x) {
        if (isFull()) {
            return false;
        }
        if (front == -1) { // If deque is empty
            front = rear = 0;
        }
        else if (rear == size - 1) { // Wrap around
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = x;
        return true;
    }
    // Pops an element from the front of the deque.
    int popFront() {
        if (isEmpty()) {
            return -1; // Deque is empty
        }
        int ans = arr[front];
        if (front == rear) { // If the deque is now empty after popping
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
        return ans;
    }
    // Pops an element from the back of the deque.
    int popRear() {
        if (isEmpty()) {
            return -1; // Deque is empty
        }
        int ans = arr[rear];
        if (front == rear) { // If the deque is now empty after popping
            front = rear = -1;
        }
        else {
            rear = (rear - 1 + size) % size; // Wrap around
        }
        return ans;
    }
    // Returns the first element of the deque.
    int getFront() {
        return isEmpty() ? -1 : arr[front];
    }
    // Returns the last element of the deque.
    int getRear() {
        return isEmpty() ? -1 : arr[rear];
    }
    // Returns true if the deque is empty.
    bool isEmpty() {
        return front == -1;
    }
    // Returns true if the deque is full.
    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear + 1) % size == front;
    }
};
int main() {
    Deque dq(5); // Create a deque of size 5
    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushFront(30);
    cout << "Front: " << dq.getFront() << endl; // Should print 30
    cout << "Rear: " << dq.getRear() << endl;   // Should print 20
    dq.popFront();
    cout << "After popFront, Front: " << dq.getFront() << endl; // Should print 10
    dq.popRear();
    cout << "After popRear, Rear: " << dq.getRear() << endl;   // Should print 10
    return 0;
}